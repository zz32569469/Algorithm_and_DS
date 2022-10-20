int deg[MXN];
set<int>edge[MXN];
vector<int>path;

void dfs(int x){
    while(!edge[x].empty()){
        int u= *edge[x].begin();
        edge[x].erase(u);
        edge[u].erase(x);
        dfs(u);
    }
    path.PB(x);
}

int Eulur_circuit(int s,int n,int m){// s 為起點， n 為點數， m 為邊數
    for(int i=1;i<=n;i++) if(deg[i]&1) return 0;//條件每個點度數為偶數
    
    dfs(s,s);
    reverse(path.begin(),path.end());
    if(path.size()!=m+1) return 0; 
    return 1;
}//無向圖歐拉回路，每個邊只能走一次。
