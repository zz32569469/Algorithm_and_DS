struct rec{
    int u,v,w;
    bool operator<(const rec _x){
        return w<_x.w;
    }
};

vector<rec>edge;
int f[MXN];

void init(int n){
    for(int i=1;i<=n;i++) f[i]=i;
}

int find(int x){
    if(x==f[x]) return f[x];
    return f[x]=find(f[x]);
}

void merge(int x,int y){
    y=find(y),x=find(x);
    if(y!=x) f[y]=x;
}

int MST(int n){
    init(n);

    sort(edge.begin(),edge.end());//權重排序

    int sum=0,cnt=0;
    for(int i=0;i<m;i++){
        if(find(edge[i].u)!=find(edge[i].v)){
            merge(edge[i].u,edge[i].v);
            sum+=edge[i].w;
            cnt++;
        }
    }
  
    if(cnt!=n-1) return -1;//邊數量< n-1 則無法形成 Minimum Spanning Tree
    else return sum; // 回傳 Minimum Spanning Tree 的總權重
}
