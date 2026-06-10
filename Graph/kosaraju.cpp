const int N = 1e5 + 5;
vector<int> adj[N], revadj[N], conadj[N];
vector<ll> value(N), concoin(N);
vector<int> component;
stack<int> st;
vector<bool> vis(N);
 
void dfs(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if(!vis[v]) dfs(v);
    st.push(u);
}
 
void dfs1(int u) {
    vis[u] = 1;
    for (auto v : revadj[u]) if(!vis[v]) dfs1(v);
    component.push_back(u);    
}
 
void dfs2(int u) {
    vis[u] = 1;
    ll mx = 0;
    for (auto v : conadj[u]) { 
        if(!vis[v]) dfs2(v);
        mx = max(mx, value[v]);
    }
    value[u] = mx + concoin[u];
}

vector<int> coin(n + 5);
for (int i = 1; i <= n; i++) cin >> coin[i];
for (int i = 1; i <= m; i++) {
    adj[u].push_back(v);
    revadj[v].push_back(u);
}
for (int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
vector<int> roots(n + 5, 0);
vector<int> connodes;
for (int i = 1; i <= n; i++) vis[i] = 0;
while(!st.empty()) {
    int tp = st.top();
    st.pop();
    if(!vis[tp]) {
        dfs1(tp);
        int root = *min_element(component.begin(), component.end());
        ll sum = 0;
        for (auto node : component) roots[node] = root, sum += coin[node];
        concoin[root] = sum;
        connodes.push_back(root);
        component.clear();
    }
}
for (int u = 1; u <= n; u++) {
    for (auto v : adj[u]) {
        if(roots[u] != roots[v]) conadj[roots[u]].push_back(roots[v]);
    }
}
for (int i = 1; i <= n; i++) vis[i] = 0;
for (auto u : connodes) if(!vis[u]) dfs2(u);
