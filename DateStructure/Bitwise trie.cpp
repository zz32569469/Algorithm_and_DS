struct trie{
    const static int Max_bit=30;

    trie *nxt[2];  // 差別
    int cnt;    //紀錄有多少個數字以此節點結尾
    int sz;     //有多少數字的前綴包括此節點
    trie(){
        memset(nxt,0,sizeof(nxt));
        cnt=sz=0;
    }

    void insert(int x){
        trie *now = this;  // 每次從根結點出發
        for(int i=Max_bit;i>=0;i--){
            now->sz++;
            if(now->nxt[x>>i&1] == nullptr){
                now->nxt[x>>i&1] = new trie();
            }
            now = now->nxt[x>>i&1];  //走到下一個位元
        }
        now->cnt++;
        now->sz++;
    }
};