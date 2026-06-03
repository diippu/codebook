using ll = long long;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vector<ll> t(4 * N, 0), lazy(4 * N, 0);
 
void push(int ind, int al, int ar) {
    int mid = al + (ar - al) / 2;
    lazy[2 * ind] += lazy[ind]; 
    t[2 * ind] += (mid - al + 1) * lazy[ind];
    lazy[2 * ind + 1] += lazy[ind];
    t[2 * ind + 1] += (ar - mid) * lazy[ind];
    lazy[ind] = 0; 
}
 
void update(int ind, int al, int ar, int l, int r, int v) {
    if(r < al or l > ar) return;
    if(l <= al and ar <= r) {
        t[ind] += 1ll * (ar - al + 1) * v;
        lazy[ind] += v;
        return;
    }
 
    push(ind, al, ar);
    int mid = al + (ar - al) / 2;
    update(2 * ind, al, mid, l, r, v);
    update(2 * ind + 1, mid + 1, ar, l, r, v);
    t[ind] = t[2 * ind] + t[2 * ind + 1];
}
 
ll query(int ind, int al, int ar, int l, int r) {
    if(r < al or l > ar) return 0;
    if(l <= al and ar <= r) {
        return t[ind];
    }
 
    push(ind, al, ar);
    int mid = al + (ar - al) / 2;
    ll left = query(2 * ind, al, mid, l, r);
    ll rgt = query(2 * ind + 1, mid + 1, ar, l, r);
    return left + rgt;
}
