struct disjoint_set{
    vector<int>f;//屬於哪個集合

    void init(int n){
        f.resize(n+1);
        for(int i=0;i<=n;i++) f[i]=i;
    }

    int find(int x){
        if(x==f[x]) return f[x];
        return f[x]=find(f[x]);//路徑壓縮
    }

    void merge(int x,int y){ //合併集合，將 y 集合合併到 x 集合
        int rt_y=find(y), rt_x=find(x);
        if(rt_y!=rt_x) f[rt_y]=rt_x;
    }

    bool in_the_same_set(int x, int y){//判斷 x, y是否為同一集合
        return find(x)==find(y);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void MERGE(int x, int y){       // MERGE
        if(!in_the_same_set(x, y)) merge(x, y);
    }
};
