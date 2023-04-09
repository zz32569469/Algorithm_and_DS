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

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int>a(n);
    set<int>s;

    for(auto &x:a) cin>>x;

    sort(all(a));

    int cnt=0,now=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(0);

    while(1){
        now=pq.top();
        pq.pop();
        if(now) cnt++;

        if(cnt==k){
            cout<<now;
            return ;
        }

        
        for(auto x:a){
            int tmp=x+now;
            if(!s.count(tmp)){
                s.insert(tmp);
                pq.push(tmp);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}
