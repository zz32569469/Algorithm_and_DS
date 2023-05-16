vector<int>prime;
bool isPrime[MXN];

void init(int n){
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
