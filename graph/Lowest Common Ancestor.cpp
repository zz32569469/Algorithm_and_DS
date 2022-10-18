const int LgN=31;//log2(1e9)+1;

int fa[MXN],anc[MXN][LgN+5];

void Count_Anc(int n){
  for(int i=1;i<=n;i++){
        anc[i][0]=fa[i];
   }
  
  for(int i=1;i<LgN;i++){
        for(int j=1;j<=n;j++){
            anc[j][i]=anc[anc[j][i-1]][i-1];
        }
   }
}

int lift(int x,int k){//計算 x 的 k 倍祖先
    int ret=x;
    for(int i=0;i<LgN;i++){
        if((k>>i)&1) x=anc[x][i];
    }
    return ret;
}
