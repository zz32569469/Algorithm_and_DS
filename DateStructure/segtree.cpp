#define cl(x) x*2
#define cr(x) x*2+1//1-base
  
const int MXN = 2e5+5; 

struct segtree{//假設維護區間和
    vector<int>segtree, a, tag;
    int n, ql, qr, v;

    void init(int n){//初始化及設定 a 
        segtree.resize(n<<2+1);
        a.resize(n+1);
        tag.resize(n<<2+1);
    }

    void data_update(int i){//如何更新資料
        segtree[i] = segtree[cl(i)] + segtree[cr(i)];
    }

    void push(int i, int l, int r){
        if(tag[i] != 0){
            segtree[i] += tag[i]*(r-l+1); 
            if(l != r){ 
                tag[cl(i)] += tag[i];
                tag[cr(i)] += tag[i];
            }
            tag[i] = 0;
        }
    }

    void pull(int i, int l, int r){
        int mid = (l+r)/2;
        if(l==r) return ;
        push(cl(i), l, mid); push(cr(i), mid+1, r);
        data_update(i);
    }


    void build(int i, int l, int r){//設定 segtree ，不一定要有
        if(l == r){ 
            segtree[i] = a[l];
            return;
        }
        int mid=(l+r)/2; 
        build(cl(i), l, mid); 
        build(cr(i), mid+1, r);
    
        data_update(i);
    }
    
    int query(int i, int l, int r){
        push(i, l, r);
        
        if(ql <= l && r <= qr){ 
            return segtree[i];
        }
        int mid=(l+r)/2,  ret=0;
        if(ql<=mid) ret+=query(cl(i), l, mid);
        if(qr> mid) ret+=query(cr(i), mid+1, r);
        pull(i, l, r);
        return ret;
    }

    void update(int i, int l, int r){//區間修改
        push(i, l, r);
        if(ql<=l && r<=qr){
            tag[i] += v;
            return;
        }
        int mid=(l+r)/2;
        if(ql<=mid)  update(cl(i), l, mid);
        if(qr> mid)  update(cr(i), mid+1, r);
        pull(i, l, r);
    }

    void Build(){build(1, 1, n);}
    
    int Query(int _ql, int _qr){//詢問
        ql=_ql, qr=_qr;
        return query(1, 1, n);
    }

    void Update(int _v, int _ql, int _qr){//修改
        v=_v, ql=_ql, qr=_qr;
        update(1, 1, n);
    }
}seg_tree;//1-base
        v=_v, ql=_ql, qr=_qr;
        update(1, 1, n);
    }
}seg_tree;//1-base
