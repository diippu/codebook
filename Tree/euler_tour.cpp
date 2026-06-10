const int N = 2e5 + 5;

vector<int> adj[N], flat(N), a(N), st(N), en(N);
int t;

void dfs(int u, int p) {
    st[u] = ++t;;
    for (auto v : adj[u]) if(v != p) dfs(v, u);
    en[u] = t;
}

dfs(1, 0);
for (int i = 1; i <= n; i++) flat[st[i]] = a[i];
SGTree sg(t);
sg.build(1, 1, t, flat);
