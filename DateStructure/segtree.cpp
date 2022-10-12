#define cl(x) x*2
#define cr(x) x*2+1//1-base

//假設維護區間最小值

int segtree[MXN<<2];
int a[MXN];

 
void build(int i,int l,int r){//初始化，不一定要有
    if(l == r){ 
        segtree[i] = a[l];
        return;
    }
    int mid=(l+r)/2; 
    build(cl(i),l,mid); 
    build(cr(i),mid+1,r);
  
    segtree[i] = min(segtree[cl(i)], segtree[cr(i)]);
}
 
int query(int i,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){ 
        return segtree[i];
    }
    int mid=(l+r)/2, ret=inf;
 
    if(ql<=mid) ret = min(ret, query(cl(i),l,mid,ql,qr));
    if(qr> mid) ret = min(ret, query(cr(i),mid+1,r,ql,qr));
    return ret;
}
 
void update(int i,int l,int r,int pos,int val){//單點修改
    if(l == r){ 
        segtree[i] = val;
        return;
    }
    int mid=(l+r)/2;
    if(pos <= mid) update(cl(i),l,mid,pos,val);
    else update(cr(i),mid+1,r,pos,val);
 
    segtree[i] = min(segtree[cl(i)], segtree[cr(i)]);
}
