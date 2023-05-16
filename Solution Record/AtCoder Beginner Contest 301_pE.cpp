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

struct pt{
    int x,y;
    pt(){}
    pt(int _x,int _y){
        x=_x,y=_y;
    }
};

string a[305];
int dis[21][21];
int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};
map<pair<int,int>,int>mp;

void bfs(pt source,int h,int w){
    queue<pair<pt,int>>q;

    q.push({source,0});
    bool vst[305][305]={};

    while(!q.empty()){
        auto [now,step]=q.front();
        q.pop();

        if(a[now.y][now.x]=='o' || a[now.y][now.x]=='S' || a[now.y][now.x]=='G'){
            dis[mp[{source.x,source.y}]][mp[{now.x,now.y}]]=step;
        }

        for(int i=0;i<4;i++){
            pt nxt=pt(now.x+dirx[i],now.y+diry[i]);

            if(nxt.x>=w || nxt.x<0 || nxt.y>=h || nxt.y<0) continue;
            if(a[nxt.y][nxt.x]=='#' || vst[nxt.y][nxt.x]) continue;

            vst[nxt.y][nxt.x]=1;
            q.push({nxt,step+1});
        }
    }
}

void solve(){
    int h,w,t;
    cin>>h>>w>>t;

    memset(dis,INF,sizeof(dis));
    pt S,G;
    int cnt=0;
    vector<pt>v;

    for(int i=0;i<h;i++){
        cin>>a[i];
        for(int j=0;j<w;j++){
            if(a[i][j]=='o'){
                mp[{j,i}]=cnt++;
                v.PB(pt(j,i));
            }

            else if(a[i][j]=='S'){
                S=pt(j,i);
            }

            else if(a[i][j]=='G'){
                G=pt(j,i);
            }
        }
    }

    vector<vector<int>>dp(1<<cnt);
    for(int i=0;i<(1<<cnt);i++){
        dp[i].resize(cnt,INF);
    }


    mp[{S.x,S.y}]=cnt;
    mp[{G.x,G.y}]=cnt+1;


    for(auto u:v) bfs(u,h,w);
    bfs(S,h,w);

    int ans=0;
    if(dis[cnt][cnt+1]>t){
        cout<<-1;
        return;
    }

    for(int i=0;i<cnt;i++){
        dp[1<<i][i]=dis[i][cnt];
    }

    for(int s=0;s<(1<<cnt);s++){
        for(int last=0;last<cnt;last++){
            if(!(s&(1<<last))) continue;
            for(int nxt=0;nxt<cnt;nxt++){
                if((1<<nxt)&s) continue;
                dp[s|(1<<nxt)][nxt]=min( dp[s|(1<<nxt)][nxt],dp[s][last]+dis[last][nxt]);
            }
        }
    }

    for(int s=0;s<(1<<cnt);s++){
        for(int last=0;last<cnt;last++){
            if(dp[s][last]+dis[last][cnt+1]<=t){
                int now=0;
                for(int i=0;i<cnt;i++) if(((1<<i)&s)) now++;
                ans=max(ans,now);
            }
        }
    }
    cout<<ans;
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
