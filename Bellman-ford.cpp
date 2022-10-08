struct rec{
    int u,v,w;
};
int dis[MXN];//原點到其他點的最短距離
int p[MXN];
rec edge[MXN];
vector<int>path;

bool relaxtion(int u,int v,int w){
    if(dis[v]>dis[u]+w){
        dis[v]=dis[u]+w;
        return 1;
    }
    return 0;
}

int bellmanford(){
		memset(dis,0x3f3f3f3f3f3f3f3f,sizeof(dis));

    int ptr=-1;
    for(int i=0;i<n&&ptr;i++){//第 n 次還可以鬆弛，則有負環
        ptr=0;
        for(int j=0;j<m;j++){
            if(relaxtion(edge[j].u,edge[j].v,edge[j].w)){
                ptr=edge[j].v;
                p[edge[j].v]=edge[j].u;//紀錄此點是誰鬆弛的
            }
        }
    }

    return ptr;
}

vector<int> findpath(){
	  vector<int> cycle;

    int ptr=bellmanford();
    if(!ptr) return cycle;

    for(int i = 0; i < n; i++) ptr = p[ptr];//若有負環，代表每一次都被鬆弛，所以回到 n 次前

    for(int v = ptr;; v = p[v]){
        cycle.push_back(v);
        if(v == ptr && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());

		return cycle;
}
//Bellman-ford O(NM) 找負環，單源最短路徑。
