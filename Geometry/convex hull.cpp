struct pt{
    ll x,y;
    pt(){}
    pt(ll _x,ll _y){
        x=_x,y=_y;
    }

    pt operator-(const pt &a){
        return pt(x-a.x,y-a.y);
    }

    bool operator<(const pt &a){
        return x<a.x||((x==a.x)&&(y<a.y));
    }

    bool operator==(const pt &a){
        return x==a.x&&y==a.y;
    }

    bool operator!=(const pt &a){
        return x!=a.x||y!=a.y;
    }

    friend ll cross(pt &o,pt &a,pt &b){//外積，小於 0 是逆時針
        pt lhs=o-a; 
        pt rhs=o-b;
        return lhs.x*rhs.y-lhs.y*rhs.x;
    }

    friend ll area(pt &a,pt &b,pt &c){
        return abs(cross(a,b,c));
    }
};

vector<pt> a;
vector<pt> stk;

void convex_hull(){
    int top=0;
    sort(a.begin(),a.end());
    stk.clear();

    for(int i=0;i<n;i++){
        while(top>=2&&cross(stk[top-2],stk[top-1],a[i])<0){
            stk.pop_back();
            top--;
        }
        stk.push_back(a[i]);
        top++;
    }//下凸包

    for(int i=n-2,tt=top+1;i>=0;i--){
         while(top>=tt&&cross(stk[top-2],stk[top-1],a[i])<0){
            stk.pop_back();
            top--;
        }
        stk.push_back(a[i]);
        top++;
    }//上凸包
    stk.pop_back();
}
