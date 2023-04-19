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
const ll MOD=998244353;
const int LgN=log2(1e6)+1;
const int P=37;
const ld EXP=1e-11;

string s="1";

int mul(int x,int hst){
    int tmp=hst;
    int ret=1;
    int base=10;
    while(tmp){
        if(tmp&1) ret=ret*base%MOD;
        base=base*base%MOD;

        tmp>>=1;
    }

    ret=ret*(s[x]-'0')%MOD;

    return ret;
}

void solve(){
    int st=0;
    int x=1;

    int q;
    cin>>q;

    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int y;
            cin>>y;
            s.PB(y+'0');
            x=x*10+y;
            x%=MOD;
        }
        else if(op==2){
            x-=mul(st,s.size()-1-st);
            x=(x+MOD)%MOD;
            st++;
        }
        else {
            cout<<x<<'\n';
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
