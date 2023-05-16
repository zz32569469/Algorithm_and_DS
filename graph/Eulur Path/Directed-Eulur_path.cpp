vector<int>edge[MXN];
vector<int>path;
int degin[MXN],degout[MXN];

void dfs(int x){
    while(!edge[x].empty()){
        int u=edge[x].back();
        edge[x].pop_back();
        dfs(u);
    }
    path.PB(x);
}

int Eulur_path(int n,int m){//這裡設 1 為起點 ， n 為終點
    degin[1]++;
    degin[n]--;
    for(int i=1;i<=n;i++){
        if(degout[i]!=degin[i]) return 0;
    }

    dfs(1);
    reverse(path.begin(),path.end());
    if(path.size()!=m+1) return 0;
    return 1;
}//起點 degin[st]+1==degout[st]，終點 degin[ed]-1==degout[ed]
