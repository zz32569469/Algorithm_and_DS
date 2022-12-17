int a[MXN];
int dp[MXN][30],flg[MXN];

void init(){
    for(int i=1;i<=n;i++) dp[i][0]=len[i];

    for(int i=1;i<=flg[n];i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            dp[j][i]=max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);//更新區間 j ~ j+2^i
        }
    }
}

void initRMQ(){//初始化 log2(i) 的值
    flg[0]=-1;
    for(int i=1;i<MXN;i++){
        flg[i]=((i&i-1)==0)? flg[i-1]+1:flg[i-1];
    }
}

int RMQ(int l,int r){//詢問區間 l ~ r 的最大值
    int k=flg[r-l+1];
    return max(dp[l][k],dp[r-(1<<k)+1][k]);//答案為 max (l ~ l+2^k , r-2^k+1 ~ r)
}
