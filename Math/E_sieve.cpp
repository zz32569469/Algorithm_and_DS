struct E_sieve{
    vector<int>prime;
    vector<int>isPrime;

    vector<vector<int>>dec;

    void init(int n){
        isPrime.resize(n+1);
        dec.resize(n+1);
        isPrime[1]=isPrime[0]=1;
        
        for(int i=2;i<=n;i++){
            if(!isPrime[i]){
                prime.PB(i);
                for(int j=1;j*i<=n;j++){
                    dec[i*j].PB(i);
                    isPrime[i*j]=1;
                }
            }
        }
    }
};