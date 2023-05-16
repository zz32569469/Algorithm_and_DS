vector<vector<int>> mat_mul(vector<vector<int>> a,vector<vector<int>> b,int mod){
    int n=a.size();

    vector<vector<int>> res(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                res[i][j]+=a[i][k]*b[k][j];
                res[i][j]%=mod;
            }
        }
    }
    return res;
}

vector<vector<int>> mat_pow(vector<vector<int>> base,int x,int m){
    int n=base.size();
    vector<vector<int>> res(n,vector<int>(n));

    res[1][0]=1;

    while(x){
        if(x&1) res=mat_mul(base,res,m);
        base=mat_mul(base,base,m);
        x>>=1;
    }
    return res;
}
