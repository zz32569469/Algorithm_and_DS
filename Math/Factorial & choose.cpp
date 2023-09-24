const ll MOD=1e9+7;
const ll MXN=5e3+5;

ll fac[MXN],inv[MXN],invf[MXN];
void initf(){
	fac[1]=fac[0]=1;
	inv[0]=inv[1]=1;
    invf[0]=invf[1]=1;
    for(int i=2;i<MXN;i++){
        fac[i]=(fac[i-1]*i)%MOD;
        inv[i]=MOD-(MOD/i*inv[MOD%i])%MOD;
        invf[i]=invf[i-1]*inv[i]%MOD;
    }
}

ll C(int n,int m){
    if(n<m||n<0) return 0;
    return (((fac[n]*invf[m])%MOD)*invf[n-m])%MOD;
}
