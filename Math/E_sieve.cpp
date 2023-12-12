struct E_sieve{
    vector<int>prime;
    vector<int>isPrime;

    void init(int n){
        isPrime.resize(n+1);
        isPrime[1]=isPrime[0]=1;
        
        for(int i=2;i<=n;i++){
            if(!isPrime[i]){
                prime.PB(i);
                for(int j=i;j*i<=n;j++){
                    isPrime[i*j]=1;
                }
            }
        }
    }
};
