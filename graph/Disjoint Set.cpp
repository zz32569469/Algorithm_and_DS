struct disjoint_set{
    const static int MXN=2e5+5;
    int f[MXN], cnt[MXN];//屬於哪個集合，集合 x 有幾個人

    void init(int n) {for(int i=1;i<=n;i++) f[i]=i, cnt[i]=1;}

    int find(int x){
        if(x==f[x]) return f[x];
        return f[x]=find(f[x]);//路徑壓縮
    }

    void merge(int x,int y){ //合併集合，將 y 集合合併到 x 集合
        y=find(y), x=find(x);

        cnt[x]+=cnt[y];
        cnt[y]=0;

        if(y!=x) f[y]=x;
    }
};
