#define lowbit(x) x&(-x)

int bit[MXN];

int query(int x){
    int ret=0;
    while(x){
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

void update(int x,int v){
    while(x<=n){
        bit[x] += v;
        x += lowbit(x);
    }
}//單點修改，區間查詢。//區間修改，單點查詢。
