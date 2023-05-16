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

int dp[20][200];
int a[20];

int f(int pos,bool limit,int sum){
    if(!pos) return sum;
    if(!limit && ~dp[pos][sum]) return dp[pos][sum];

    int up=limit? a[pos]:9;
    int res=0;

    for(int i=0;i<=up;i++){
        res=(res+f(pos-1,limit && i==up,sum+i))%MOD;
    }

    if(!limit) dp[pos][sum]=res;

    return res;
}

int cal(int x){
    int len=0;
    while(x){
        a[++len]=x%10;
        x/=10;
    }

    return f(len,1,0);
}

void solve(){
    int l,r;
    cin>>l>>r;

    cout<<(cal(r)-cal(l-1)+MOD)%MOD;
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        solve();
        cout<<'\n';
    }
}
