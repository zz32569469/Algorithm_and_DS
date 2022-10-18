const int LgN=31;//log2(1e9)+1;

int fa[MXN],anc[MXN][LgN+5];

void Count_LCA(int n){
  for(int i=1;i<=n;i++){
        anc[i][0]=fa[i];
   }
  
  for(int i=1;i<LgN;i++){
        for(int j=1;j<=n;j++){
            anc[j][i]=anc[anc[j][i-1]][i-1];
        }
   }
}
