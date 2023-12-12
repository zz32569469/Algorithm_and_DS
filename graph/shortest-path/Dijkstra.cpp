struct dijkstra{
    static const int MXN = 2e5+5;
    static const int INF  = 0x3f3f3f3f3f3f3f3f;

    struct info{
        int to, w;
    };

    int dis[MXN];//原點到其他點的最短距離
    bool vst[MXN]={};
    vector<info>edge[MXN];

    void add_edge(int u, int v, int w){ //加入邊
        edge[u].PB({v, w});
    }

    bool relaxtion(int u,int v,int w){
        if(dis[v]>dis[u]+w){
            dis[v]=dis[u]+w;
            return 1;
        }
        return 0;
    }

    int solve(int src, int dst){//起點, 終點
        memset(dis,INF,sizeof(dis));
        dis[src]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        pq.push({0,src});

        while(!pq.empty()){
            auto [d, idx]=pq.top();
            pq.pop();
            if(vst[idx]) continue;

            vst[idx]=1;
            for(int i=0;i<edge[idx].size();i++){
                int u=idx,v=edge[idx][i].to,w=edge[idx][i].w;

                if(relaxtion(u,v,w)) pq.push({dis[v],v});
            }
        }

        return dis[dst];
    }//dijkstra 無負邊權 O(MlogN+N)

};
