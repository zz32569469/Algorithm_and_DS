const int LgN=31;//log2(1e9)+1;

int fa[MXN],anc[MXN][LgN+5],tin[MXN],tout[MXN];
vector<int>edge[MXN];
bool vst[MXN];
int tt=1;

void dfs(int x){//計算時間戳記
    if(vst[x]) return ;
    vst[x]=1;
    tin[x]=tt++;
    for(auto u:edge[x]){
        if(vst[u]) continue;
        dfs(u);
    }
    tout[x]=tt++;
}

void Count_Anc(int n,int rt){//點數量，根節點
    fa[rt]=rt;
    dfs(rt);

    for(int i=1;i<=n;i++){
        anc[i][0]=fa[i];
    }
  
    for(int i=1;i<LgN;i++){
        for(int j=1;j<=n;j++){
            anc[j][i]=anc[anc[j][i-1]][i-1];
        }
    }
}

int lift(int x,int k){//計算 x 的 k 輩祖先
    int ret=x;
    for(int i=LgN;i>=0;i--){
        if(k&(1<<i)) ret=anc[ret][i];
    }
    return ret;
}

bool isAncestor(int u,int v){
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}

int GetLca(int u,int v){
    if(isAncestor(u,v)) return u;
    else if(isAncestor(v,u)) return v;
    else {
        for(int i=LgN-1;i>=0;i--){
            if(!isAncestor(anc[u][i],v)) u=anc[u][i];
        }
    }
    return anc[u][0];
}
