struct trie{
    trie *nxt[26];
    int cnt, sz;
    trie(){
        memset(nxt ,0, sizeof(nxt));
        cnt=sz=0;
    }

    void insert(string s){
        trie *now = this;  // 每次從根結點出發
        for(auto i:s){
            now->sz++;
            if(now->nxt[i-'a'] == nullptr){
                now->nxt[i-'a'] = new trie();
            }
            now = now->nxt[i-'a'];  //走到下一個字母
        }
        now->cnt++;
        now->sz++;
    }

    int query_prefix(string s){  //查詢有多少前綴為 s
        trie *now = this;    // 每次從根結點出發
        for(auto i:s){
            if(now->nxt[i-'a'] == nullptr){
                return 0;
            }
            now = now->nxt[i-'a']; 
        }
        return now->sz;
    }

    int query_count(string s){  //查詢字串 s 出現次數
        trie *now = this;    // 每次從根結點出發
        for(auto i:s){
            if(now->nxt[i-'a'] == nullptr){
                return 0;
            }
        now = now->nxt[i-'a'];
    }
    return now->cnt;
}

};//字典樹, a-z , O(|s|)