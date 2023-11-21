vector<Pt> convex_hull(vector<Pt> a){
    int top=0;
    sort(a.begin(),a.end());

    vector<Pt>stk;

    for(int i=0;i<n;i++){
        while(top>=2 && cross(stk[top-2], stk[top-1], a[i])<0){
            stk.pop_back();
            top--;
        }
        stk.push_back(a[i]);
        top++;
    }//下凸包

    for(int i=n-2,tt=top+1;i>=0;i--){
         while(top>=tt && cross(stk[top-2], stk[top-1], a[i])<0){
            stk.pop_back();
            top--;
        }
        stk.push_back(a[i]);
        top++;
    }//上凸包
    stk.pop_back();

    return stk;
}
