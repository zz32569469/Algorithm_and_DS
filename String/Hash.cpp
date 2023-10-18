const int P=37;
//71,57,31

int ha[MXN],a[MXN],base[MXN];

int segment_Hash(int l,int r){
    if(l==0) return ha[r];
    int ret=(ha[r]-ha[l-1]*base[r-l+1])%MOD;
    while(ret<0) ret=(ret+MOD)%MOD;
    return ret;
}

void init(int n){//字串長度
    base[0]=1;
    for(int i=1;i<n;i++) base[i]=base[i-1]*P%MOD;
}

void creatHash(string s){
    
    for(int i=0;i<s.size();i++) a[i]=s[i]-'A'+1;
    ha[0]=a[0];

    for(int i=1;i<s.size();i++) ha[i]=(P*ha[i-1]+a[i])%MOD;
}

