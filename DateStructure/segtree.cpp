#define cl(x) x*2
#define cr(x) x*2+1//1-base

#include<bits/stdc++.h> 
#define ll long long 
#define ld long double 
#define int long long 
#define endl '\n'; 
#define cl(x) x*2 
#define cr(x) x*2+1//1-base 
#define lowbit(x) x&(-x) 
#define PB push_back 
#define SZ(x) (int)x.size() 
#define FZ(x) memset(x,  0,  sizeof(x)) 
#define all(x) x.begin(), x.end() 
  
using namespace std; 
  
const int MXN = 2e5+5; 
const int INF = 0x3f3f3f3f3f3f3f3f; 
const ll MOD = 998244353; 
const int LgN = log2(1e6)+1; 
const int P = 37; 
const ld EXP = 1e-11;

struct segtree{//假設維護區間和
    int segtree[MXN<<2], a[MXN], tag[MXN<<2];
    int n, ql, qr, v;

    void init(){
        memset(segtree, 0, sizeof(segtree));
        memset(tag, 0, sizeof(tag));
        memset(a, 0, sizeof(a));
    }

    void push(int i, int l, int r){
        if(tag[i] != 0){
            segtree[i] += tag[i]*(r-l+1); 
            if(l != r){ 
                tag[cl(i)] += tag[i];
                tag[cr(i)] += tag[i];
            }
            tag[i] = 0;
        }
    }

    void pull(int i, int l, int r){
        int mid = (l+r)/2;
        if(l==r) return ;
        push(cl(i), l, mid); push(cr(i), mid+1, r);
        segtree[i] = segtree[cl(i)] + segtree[cr(i)];
    }


    void build(int i, int l, int r){//初始化，不一定要有
        if(l == r){ 
            segtree[i] = a[l];
            return;
        }
        int mid=(l+r)/2; 
        build(cl(i), l, mid); 
        build(cr(i), mid+1, r);
    
        segtree[i] = segtree[cl(i)]+segtree[cr(i)];
    }
    
    int query(int i, int l, int r){
        push(i, l, r);
        
        if(ql <= l && r <= qr){ 
            return segtree[i];
        }
        int mid=(l+r)/2,  ret=0;
        if(ql<=mid) ret+=query(cl(i), l, mid);
        if(qr> mid) ret+=query(cr(i), mid+1, r);
        pull(i, l, r);
        return ret;
    }

    void update(int i, int l, int r){//區間修改
        push(i, l, r);
        if(ql<=l && r<=qr){
            tag[i] += v;
            return;
        }
        int mid=(l+r)/2;
        if(ql<=mid)  update(cl(i), l, mid);
        if(qr> mid)  update(cr(i), mid+1, r);
        pull(i, l, r);
    }
    
    int Query(int _ql, int _qr){//詢問
        ql=_ql, qr=_qr;
        return query(1, 1, n);
    }

    int Update(int _v, int _ql, int _qr){//修改
        v=_v, ql=_ql, qr=_qr;
        update(1, 1, n);
    }
}seg_tree;//1-base

void solve(){
    


}

signed main() { 
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
 
    int t = 1; 
    //cin >> t;

    while(t--){
        solve(); 
        cout<<'\n'; 
    } 
}
