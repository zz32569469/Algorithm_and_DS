#define cl(x) x*2
#define cr(x) x*2+1//1-base

//假設維護區間和

int segtree[MXN<<2];
int a[MXN];
int tag[MXN<<2];

void push(int i,int l,int r){
    if(tag[i] != 0){
        segtree[i] += tag[i]*(r-l+1); 
        if(l != r){ 
            tag[cl(i)] += tag[i];
            tag[cr(i)] += tag[i];
        }
        tag[i] = 0;
    }
}

void pull(int i,int l,int r){
    int mid = (l+r)/2;
    if(l==r) return ;
    push(cl(i),l,mid); push(cr(i),mid+1,r);
    segtree[i] = segtree[cl(i)] + segtree[cr(i)];
}


void build(int i,int l,int r){//初始化，不一定要有
    if(l == r){ 
        segtree[i] = a[l];
        return;
    }
    int mid=(l+r)/2; 
    build(cl(i),l,mid); 
    build(cr(i),mid+1,r);
  
    segtree[i] = segtree[cl(i)]+segtree[cr(i)];
}
 
int query(int i,int l,int r,int ql,int qr){
    push(i,l,r);
    
    if(ql <= l && r <= qr){ 
        return segtree[i];
    }
    int mid=(l+r)/2, ret=0;
    if(ql<=mid) ret+=query(cl(i),l,mid,ql,qr);
    if(qr> mid) ret+=query(cr(i),mid+1,r,ql,qr);
    pull(i,l,r);
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
 
    segtree[i] = segtree[cl(i)] + segtree[cr(i)];
}

void update2(int i,int l,int r,int ql,int qr,int v){//區間修改
    push(i,l,r);
    if(ql<=l && r<=qr){
        tag[i] += v;
        return;
    }
    int mid=(l+r)/2;
    if(ql<=mid)  update2(cl(i),l,mid,ql,qr,v);
    if(qr> mid)  update2(cr(i),mid+1,r,ql,qr,v);
    pull(i,l,r);
}
