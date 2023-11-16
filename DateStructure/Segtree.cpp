#define cl(x) x*2
#define cr(x) x*2+1//1-base

struct segtree{//假設維護區間和
    struct node{
        int val;
    };
    vector<node>tree;
    vector<int>a, tag;
    int n, ql, qr, v;

    void init(int n){//初始化及設定 a 
        tree.resize(n<<2);
        a.resize(n+1);
        tag.resize(n<<2);
    }

    void data_update(int i){//如何更新資料
        tree[i].val = tree[cl(i)].val + tree[cr(i)].val;
    }

    node data_merge(node l, node r){
        node ret;
        ret.val=l.val+r.val;
        return ret;
    }

    void push(int i, int l, int r){
        if(tag[i] != 0){
            tree[i] += tag[i]*(r-l+1); 
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


    void build(int i, int l, int r){//設定 tree ，不一定要有
        if(l == r){ 
            tree[i].val = a[l];
            return;
        }
        int mid=(l+r)/2; 
        build(cl(i), l, mid); 
        build(cr(i), mid+1, r);
        data_update(i);
    }
    
    node query(int i, int l, int r){
        push(i, l, r);
        
        if(ql <= l && r <= qr){ 
            return tree[i];
        }
        int mid=(l+r)/2;

        node retl, retr, ret;
        bool okl=0, okr=0;

        if(ql<=mid) retl=query(cl(i), l, mid), okl=1;
        if(qr> mid) retr=query(cr(i), mid+1, r), okr=1;

        if(okl && okr) ret=data_merge(retl, retr);
        else if(okl) ret=retl;
        else ret=retr;

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

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Build(int n){
        init(n); 
        build(1, 1, n);
    }
    
    node Query(int _ql, int _qr){//詢問
        ql=_ql, qr=_qr;
        return query(1, 1, n);
    }

    void Update(int _v, int _ql, int _qr){//修改
        v=_v, ql=_ql, qr=_qr;
        update(1, 1, n);
    }
}seg_tree;//1-base
