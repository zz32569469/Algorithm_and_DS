struct rec{
    int to,w;
};
int dis[MXN];//原點到其他點的最短距離
bool vst[MXN];
vector<rec>edge[MXN];

bool relaxtion(int u,int v,int w){
    if(dis[v]>dis[u]+w){
        dis[v]=dis[u]+w;
        return 1;
    }
    return 0;
}

void dijkstra(int source){//原點
		memset(dis,inf,sizeof(dis));
    dis[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0,source});

    while(!pq.empty()){
        auto [d,idx]=pq.top();
        pq.pop();
        if(vst[idx]) continue;

        vst[idx]=1;
        for(int i=0;i<edge[idx].size();i++){
            int u=idx,v=edge[idx][i].to,w=edge[idx][i].w;

            if(relaxtion(u,v,w)) pq.push({dis[v],v});
        }
    }
}//dijkstra 無負邊權 O(NlogN+M)
