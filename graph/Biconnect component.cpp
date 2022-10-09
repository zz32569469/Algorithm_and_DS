#define PB push_back

struct BccVertex {
  int n,nScc,step,dfn[MXN],low[MXN];
  vector<int> E[MXN],sccv[MXN];
  int top,stk[MXN];
  void init(int _n) {  //初始化點的數量
    n = _n; nScc = step = 0;
    for (int i=0; i<n; i++) E[i].clear();//0-base
  }
  void addEdge(int u, int v)  // 加無向邊
  { E[u].PB(v); E[v].PB(u); }
  void DFS(int u, int f) {//先跑這個
    dfn[u] = low[u] = step++;
    stk[top++] = u;
    for (auto v:E[u]) {
      if (v == f) continue;
      if (dfn[v] == -1) {
        DFS(v,u);
        low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u]) {
          int z;
          sccv[nScc].clear();
          do {
            z = stk[--top];
            sccv[nScc].PB(z);
          } while (z != v);
          sccv[nScc++].PB(u);
        }
      }else
        low[u] = min(low[u],dfn[v]);
  } }
  vector<vector<int>> solve() { // 跑 Tarjan
    vector<vector<int>> res;

    for (int i=0; i<n; i++) dfn[i] = low[i] = -1;//0-base
    for (int i=0; i<n; i++){
        if (dfn[i] == -1) {
            top = 0;
            DFS(i,i);
        }
    }
    for(int i=0;i<nScc;i++){
        res.PB(sccv[i]);
    }
    return res;
  }
}graph;//點雙連通分輛(Biconnect component)//Tarjan algorithm
