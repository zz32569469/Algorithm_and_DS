int mypow(int x, int y ,int mod = MOD) {
    x %= mod;
    int res = 1 % mod;
    while(y){
        if(y&1) {
            res = res * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

int get_inv(int x) {
    return mypow(x , MOD - 2);
}
