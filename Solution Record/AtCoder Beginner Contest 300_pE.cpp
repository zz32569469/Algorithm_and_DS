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
  
const int MXN=1e6+5; 
const int INF=0x3f3f3f3f3f3f3f3f; 
const ll MOD=998244353; 
const int LgN=log2(1e6)+1; 
const int P=37; 
const ld EXP=1e-11;

int n;
map<int,int>dp;

ll fac[MXN],inv[MXN],invf[MXN];
void initf(){
    fac[1]=fac[0]=1;
	inv[0]=inv[1]=1;
    invf[0]=invf[1]=1;
    for(int i=2;i<MXN;i++){
        fac[i]=(fac[i-1]*i)%MOD;
        inv[i]=MOD-(MOD/i*inv[MOD%i])%MOD;
        invf[i]=invf[i-1]*inv[i]%MOD;
    }
}

int f(int x){
    if(x>=n) return x==n? 1:0;
    if(dp.count(x)) return dp[x];

    int res=0;
    for(int i=2;i<=6;i++) res+=f(i*x);

    res*=inv[5];
    res%=MOD;
    return dp[x]=res;
}

void solve(){
    cin>>n;

    cout<<f(1);
}
 
signed main() { 
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
 
    int t=1; 
    //cin>>t;
    initf();

    while(t--){ 
        solve(); 
        cout<<'\n'; 
    } 
}  
