const int MOD = 998244353; 

int mypow(int x, int y, int mod=MOD) {
    x%=mod;
    int ret=1;
    while(y){
        if(y&1) {
            ret=ret*x%mod;
        }
        y>>=1;
        x=x*x%mod;
    }
    return ret;
}

int get_inv(int x) {
    return mypow(x ,MOD - 2);
}
