vector<int>edge[MXN];
int deg[MXN];

vector<int> topology_sort(){
    vector<int>ret;

    queue<int>q;
    for(int i=1;i<=n;i++){
        if(!deg[i]) q.push(i);
    }

    while(!q.empty()){
        int x=q.front();
        ret.PB(x);
        q.pop();

        for(auto u:edge[x]){
            deg[u]--;
            if(!deg[u]) q.push(u);
        }
    }

    return ret;
}//可求有向無環圖 1 到 n 的最長距離
