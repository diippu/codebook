ll INF = 1e18;
struct Line {
  long long m, c;
  Line(long long m, long long c) : m(m), c(c) {}
  long long y(long long x) { return m * x + c; }
};
 
struct Node {
  Line line;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(Line l = {0, INF}) : line(l) {}
};
 
Node *root;
const int L = -1e9;
const int R = 1e9;
 
void addLine(Line new_line, Node *node, int l, int r,ll fg) {
  if (!node)
    return;
 
  int m = (l + r) >> 1;
  bool left = fg*new_line.y(l) > fg*node->line.y(l);
  bool mid = fg*new_line.y(m) > fg*node->line.y(m);
  if (mid)
    swap(new_line, node->line);
  if (l == r - 1)
    return;
  if (left != mid) {
    if (!node->left)
      node->left = new Node();
    addLine(new_line, node->left, l, m,fg);
  } else {
    if (!node->right)
      node->right = new Node();
    addLine(new_line, node->right, m, r,fg);
  }
}
void addLine(Line new_line,ll fg) { return addLine(new_line, root, L, R,fg); }
ll sol(ll x, ll y,ll fg){
 if(fg == -1){
  x = min(x,y);
  return x;
 }
 else{
  x = max(x,y);
  return x;
 }
} 
long long query(int x, Node *node, int l, int r,ll fg) {
  if (!node || l > x || r <= x)
    return INF;
  int m = (l + r) >> 1;
  if (x < m)
    return sol(node->line.y(x), query(x, node->left, l, m,fg),fg);
  else
    return sol(node->line.y(x), query(x, node->right, m, r,fg),fg);
}
long long query(int x,int fg) { return query(x, root, L, R,fg); }
