#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define int long long
#define endl '\n';
#define int long long
#define cl(x) x*2
#define cr(x) x*2+1//1-base
#define lowbit(x) x&(-x)
#define PB push_back
#define SZ(x) (int)x.size()
#define FZ(x) memset(x, 0, sizeof(x))
 
using namespace std;
 
const int MXN=1e6+5;
const int INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const int LgN=log2(1e6)+1;
const int P=37;
const ld EXP=1e-11;

ld a[MXN],b[MXN],c[MXN],d[MXN];
int n,m,k;

bool check(ld x){
    ld ratio=x/(1.0-x);

    vector<ld>v;
    for(int i=0;i<n;i++) v.PB(a[i]-b[i]*ratio);
    sort(v.begin(),v.end());

    int sum=0;
    for(int i=0;i<m;i++){
        ld x=c[i]-d[i]*ratio;
        sum+=n-(lower_bound(v.begin(),v.end(),-x)-v.begin());
    }

    return sum>=k;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        cin>>n>>m>>k;

        for(int i=0;i<n;i++) cin>>a[i]>>b[i];
        for(int i=0;i<m;i++) cin>>c[i]>>d[i];

        ld l=0.0,r=1.0;
        while(r-l>EXP){
            ld mid=(l+r)/2.0;

            if(check(mid)) l=mid;
            else r=mid;
        }

        cout<<fixed<<setprecision(10)<<l*100<<'\n';

    }
}
