struct disjoint_set{
    vector<int>f, cnt;//屬於哪個集合，集合 x 有多少元素

    void init(int n){
        f.resize(n+1);
        cnt.resize(n+1);
        for(int i=0;i<=n;i++){
            f[i]=i;
            cnt[i]=1;
        }
    }

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

    bool in_the_same_set(int x, int y){//判斷 x, y是否為同一集合
        return find(x)==find(y);
    }

    int get_set_size(int x){ // 判斷 x 所在的集合大小
        return cnt[find(x)];
    }

    void MERGE(int x, int y){       // MERGE
        if(!in_the_same_set(x, y)) merge(x, y);
    }
};
