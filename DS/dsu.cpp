const int N = 2e5 + 5;
vector<int> parent(N), siz(N);

void initi(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        siz[i] = 1;
    }
}

int findpar(int node) {
    if(node == parent[node]) return node;
    return parent[node] = findpar(parent[node]);
}
    
void unio(int u, int v) {
    u = findpar(u); 
    v = findpar(v);
    if(u == v) return;
    parent[v] = u;
    siz[u] += siz[v];   
}
