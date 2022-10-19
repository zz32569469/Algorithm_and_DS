int f[MXN];

void init(int n){
    for(int i=1;i<=n;i++) f[i]=i;
}

int find(int x){
    if(x==f[x]) return f[x];
    return f[x]=find(f[x]);//路徑壓縮
}

void merge(int x,int y){ //合併集合
    y=find(y),x=find(x);
    if(y!=x) f[y]=x;
}
