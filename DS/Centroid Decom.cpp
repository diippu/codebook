typedef struct node {
  vector<int> adj;
  int sub=1;int p;int pp;int dep=0;int vis=0;
} node;
node tree[100010];
vector<vector<pair<int,ll>>> grp(100010);
int gp=0;
int root;
int n; ll m;
ll ans = 0;
void dfs(int u,int p) {
 tree[u].sub = 1;
 for (auto v : tree[u].adj) {
     if(tree[v].vis != 1 && v != p) {
        dfs(v,u);
        tree[u].sub += tree[v].sub;
     } 
 }
}
void nextlev(int u, int p, int r, int d) {
    tree[u].pp = p;
    tree[u].dep = d;
    ll eitar = 0;
    if(p==r) {gp++; grp[gp].clear();}
    if(p != -1) {
         grp[gp].push_back({u,edge});
    } 
    for(int i = 0 ; i < tree[u].adj.size();i++) {
        int v = tree[u].adj[i];
         if(v!=p && tree[v].vis != 1) nextlev(v,u,r,d+1);
     }
    
}
void solve(int c) {
    map<ll,int> mymap;
    val[c] = 0;
    f(i,gp)  for(auto& v : grp[i+1]) mymap[ultaval[v.first]]++;
    ans += (ll)mymap[0];
    f(i,gp) {
        for(auto& v : grp[i+1])  mymap[ultaval[v.first]]--;
        // ll eita = 0;
        for(int j = 0; j < grp[i+1].size(); j++) {
       
        }
        for(auto& v : grp[i+1])  mymap[ultaval[v.first]]++;
    }
    
}
int dfs2(int u,int p,int n) {
        // printf("u -- %d v-- %d\n",u,v);
    for (auto v : tree[u].adj) {
        if(tree[v].vis != 1 && v != p && tree[v].sub > (n/2)) { return dfs2(v,u,n);}
    }
    return u;
 }
 void build(int u, int p) {
    dfs(u,p); //SYBTREE
    int c = dfs2(u,p,tree[u].sub); 
    if(p==-1) root=c;
    tree[c].p = p;
    gp=0; 
    nextlev(c,-1,c,0,0,0);
    solve(c);
    tree[c].vis = 1;
    for(auto& v : tree[c].adj)  if(tree[v].vis==0) build(v,c);
}