struct blk{
    vector<int> local;
    int golbal;
    int tag;
    blk(){
        local.clear();
        golbal=tag=0;
    }
};

blk block[MXN];
int a[MXN];
int n;

int query(int l,int r){
    int len=sqrt(n),num=(n+len-1)/len;
    int blk_l=l/len,blk_r=r/len;
    int ret=0;

    if(blk_l==blk_r){//同一塊
        for(int i=l;i<=r;i++) ret+=block[blk_l].local[i%len]+block[blk_l].tag;
        
        return ret;
    }

    for(int i=a;i<(blk_l+1)*len;i++){//左
        ret+=block[blk_l].local[i%len]+blcok[blk_l].tag;
    }

    for(int i=blk_l+1;i<blk_r;i++){//中
        ret+=blcok[i].global;
    }

    for(int i=blk_r*len;i<=b;i++){//右
        ret+=block[blk_r].local[i%len]+block[blk_r].tag;
    }

    return ret;
}

void update(int l,int r,int v){
    int len=sqrt(n),num=(n+len-1)/len;
    int blk_l=l/len,blk_r=r/len;
    int ret=0;

    if(blk_l==blk_r){//都在同一塊
        for(int i=l;i<=r;i++) block[blk_l].local[i%len]+=v;
        block[blk_l].golbal+=(r-l+1)*v;
        return ;
    }

    for(int i=l;i<(blk_l+1)*len;i++){//最左那一塊
        block[blk_l].local[i%len]+=v;
        block[blk_l].golbal+=v;
    }

    for(int i=blk_l+1;i<blk_r;i++){//中間
        block[i].golbal+=v*len;
        block[i].golbal.tag+=v;
    }

    for(int i=blk_r*len;i<=b;i++){//最右那一塊
        block[blk_r].local[i%len]+=v;
        block[blk_r].golbal+=v;
    }
}

void init(){
    int len=sqrt(n),num=(n+len-1)/len;

    for(int i=0;i<n;i++){
        block[i/len].local.push_back(a[i]);
        block[i/len].golbal+=a[i];
    }
}
