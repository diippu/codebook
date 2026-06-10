const int B = 25;
const int N = 2e5 + 5;
vector<int> adj[N];
vector<int> dep(N, -1);
vector<vector<int>> par(B, vector<int> (N, 0));
void dfs(int u, int p) {
    par[0][u] = p;
    dep[u] = dep[p] + 1;
    for (auto v : adj[u]) if(v != p) {
        dfs(v, u); 
    }
}
int lca(int u, int v) {
    if(dep[v] > dep[u]) swap(u, v);
    int d = dep[u] - dep[v];
    for (int i = B - 1; i >= 0; --i) {
        if(d & (1 << i)) u = par[i][u];
    }
    for (int i = B - 1; i >= 0; --i) {
        if(par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return (u == v ? u : par[0][u]);
}
