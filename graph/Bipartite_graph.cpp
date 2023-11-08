int color[MXN];//每個節點的顏色，顏色用0/1表示
bool vst[MXN];

bool is_bipartite=true;

vector<int>edge[MXN];

void dfs(int x,int paint){
    if(vst[x]) return;
    color[x]=color&1;
    vst[x]=1;
    
    for(auto nxt:edge[x]){
        if(vst[nxt]) continue;
        dfs(nxt,paint+1);
        if(color[nxt.v]==color[x]) is_bipartite=false;
    }
    return;
}
