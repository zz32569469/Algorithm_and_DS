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
 
void solve(){
    int n,c;
    cin>>n>>c;
 
    vector<int>a(n),b1(n),b2(n),b(n+1);
 
 
    for(auto &x:a) cin>>x;
 
    for(int i=0;i<n;i++){
        b1[i]=i+1+a[i];
        b2[i]=n-i+a[i];
 
        b[i+1]=min(b1[i],b2[i]);
    }
 
    sort(all(b));
    for(int i=1;i<=n;i++) b[i]+=b[i-1];
 
    int ans=0;
 
    for(int i=0;i<n;i++){
        int now=c;
        now-=b1[i];
        if(now<0) continue;
 
        int u=upper_bound(all(b),now)-b.begin(); 
        if(--u<=0){
            ans=max(ans,1ll);
            continue;
        }
 
        if(u==n){
            ans=n;
            break;
        }
 
        int self=min(b1[i],b2[i]);
        if(self<=b[u]-b[u-1]) ans=max(ans,u+1-( now-b[u]+self-(b[u+1]-b[u])>=0 ? 0 : 1 ));
        else ans=max(ans,u+1);
    }
 
    cout<<ans;
}
 
signed main() { 
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
 
    int t=1; 
    cin>>t;
 
    while(t--){
        solve(); 
        cout<<'\n'; 
    } 
}  
