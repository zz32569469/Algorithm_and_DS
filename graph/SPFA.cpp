struct rec{
    int to,w;
};
int dis[MXN];//原點到其他點的最短距離
bool inq[MXN],incycle[MXN],vst[MXN];
int len[MXN];
vector<rec>edge[MXN];

bool relaxtion(int u,int v,int w){
    if(dis[v]>dis[u]+w){
        dis[v]=dis[u]+w;
        return 1;
    }
    return 0;
}

int SPFA(int source){//原點
		memset(dis,0x3f3f3f3f3f3f3f3f,sizeof(dis));
    dis[source]=0;
    deque<int>dq;

    dq.PB(source);

    while(!dq.empty()){
        int u;
        if(dis[dq.front()]<dq.back()){
            u=dq.front();
            dq.pop_front();
        }
        else {
            u=dq.back();
            dq.pop_back();
        }

        //if(len[u]>n-1) return -1;
        if(len[u]>n-1) incycle[u]=1;//若鬆弛次數超過 n-1 次，則有負環

        inq[u]=0;

        for(int i=0;i<edge[u].size();i++){
            int v=edge[u][i].to,w=edge[u][i].w;

            if(relaxtion(u,v,w)&&!inq[v]&&!incycle[v]){
                dq.push_back(v);
                inq[v]=1;
                len[v]=len[u]+1;
            }
        }
    }

    return 0;
}

void dfs(int x){//誰受負環影響
    vst[x]=1;
    incycle[x]=1;

    for(auto u:edge[x]){
        if(!vst[u.to]) dfs(u.to);
    }
}//SPFA O(NM) 判斷負環，單源最短路徑
//System of Difference Constraints：對 x_j-x_i<=k 建邊 i->j 權重為 k ，再設一個起點 s 
//到所有點的權重為 0 有負環則無解，否則 s 到每個邊的距離為一組解。
