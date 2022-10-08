int dis[MXN][MXN];// 全點對最短路徑

void floyd_warshall(){
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
}// floyd_warshall O(N^3)
