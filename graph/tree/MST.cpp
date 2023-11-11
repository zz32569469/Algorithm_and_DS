// 需要 disjoint_set (ds)

struct MST{
    int n, m;// 點，邊
    struct rec{
        int u, v, w;
        bool operator<(const rec _x){
            return w < _x.w;
        }
    };
    
    vector<rec>edge;
    disjoint_set ds;

    void init(int _n, int _m){
        n=_n, m=_m;
        ds.init(n+1);
    }

    void add_edge(int u, int v, int w){ //u -> v 權重為 w 
        edge.PB({u, v, w});
    }


    int solve(){
        sort(edge.begin(),edge.end());//權重排序

        int sum=0, cnt=0;
        for(int i=0;i<m;i++){
            if(ds.FIND(edge[i].u)!=ds.FIND(edge[i].v)){
                ds.MERGE(edge[i].u,edge[i].v);
                sum+=edge[i].w;
                cnt++;
            }
        }   
  
        if(cnt!=n-1) return -1;//邊數量 < n-1 則無法形成 Minimum Spanning Tree
        else return sum; // 回傳 Minimum Spanning Tree 的總權重
    }

};//kruskal's algorithm
