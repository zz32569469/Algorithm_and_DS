struct bitwise_trie{
    const static int Max_bit=30;

    bitwise_trie *nxt[2];  // 差別
    int cnt;    //紀錄有多少個數字以此節點結尾
    int sz;     //有多少數字的前綴包括此節點
    bitwise_trie(){
        memset(nxt,0,sizeof(nxt));
        cnt=sz=0;
    }

    void insert(int x){
        bitwise_trie *now = this;  // 每次從根結點出發
        for(int i=Max_bit;i>=0;i--){
            now->sz++;
            if(now->nxt[x>>i&1] == nullptr){
                now->nxt[x>>i&1] = new bitwise_trie();
            }
            now = now->nxt[x>>i&1];  //走到下一個位元
        }
        now->cnt++;
        now->sz++;
    }

    bool erase(int x, int b=Max_bit){ // x 已經存在
        if(b == -1){
            this->cnt--;
            this->sz--;
            return this->cnt == 0;
        }
        int bit=(x>>b&1)==1;
        if(nxt[bit]!=nullptr && nxt[bit]->erase(x, b-1)){
            delete nxt[bit];
            nxt[bit] = nullptr;
        }
        this->sz--; 
        return nxt[0] == nxt[1];
    }

    int max_Xor(int x){  //回傳 x 與 bitwise trie 內的其中一個數字 Xor 後的最大值
        bitwise_trie *now = this;
        int ret = 0;
        for(int i=Max_bit;i>=0;i--){
            int bit=(x>>i&1)==1;
            if(now->nxt[!bit] != nullptr){
                ret += (1<<i);
                now = now->nxt[!bit];
            }
            else now = now->nxt[bit];
        }
        return ret;
    } 
};// bitwise trie, 一次操作 O(Max_bit)