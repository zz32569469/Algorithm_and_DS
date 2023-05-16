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
#define all(x) x.begin(),x.end()
 
using namespace std;
 
const int MXN=2e5+5;
const int INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
const int LgN=log2(1e6)+1;
const int P=37;
const ld EXP=1e-11;

pair<int,int> dp[20][10][10];
pair<int,int>s={-1,-1};
int a[20],b[20],e[20];

void init(){
    e[0]=1;
    for(int i=1;i<20;i++) e[i]=e[i-1]*10;
}

pair<int,int> f(int pos,bool up_lim,bool down_lim,bool lead_0,int mx,int mi){
    if(!pos) return {mx-mi,0};

    auto &x=dp[pos][mx][mi];
    if(!up_lim && !down_lim && !lead_0 && x!=s) return dp[pos][mx][mi];

    int up=up_lim? b[pos]:9;
    int down=down_lim? a[pos]:0;

    int res=10,tmp=0;
    for(int i=down;i<=up;i++){
        bool new_0= (lead_0 && i==0);
        int mii=new_0? 10:min(mi,i);
        int mxx=new_0? -1:max(mx,i);

        auto [u,v]=f(pos-1,up_lim && i==b[pos],down_lim && i==a[pos],new_0,mxx,mii);

        if(res>u){
            res=u;
            tmp=i*e[pos-1]+v;
        }
    }

    if(!up_lim && !down_lim && !lead_0) x={res,tmp};

    return {res,tmp};
}

void solve(){
    int l,r;
    cin>>l>>r;

    int l_len=0;
    int x=l;
    while(x){
        a[++l_len]=x%10;
        x/=10;
    }

    int r_len=0;
    x=r;
    while(x){
        b[++r_len]=x%10;
        x/=10;
    }

    cout<<f(r_len,1,1,1,-1,10).second;
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t=1;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    init();
    while(t--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        solve();
        cout<<'\n';
    }
}
