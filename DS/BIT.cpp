struct BIT {
    ll n;
    vector<ll> bit;
    BIT(ll _n) : n(_n), bit(n + 1) { }
    void add(ll x, ll val) {
        for (ll i = x; i <= n; i += (i & -i)) bit[i] += val;
    }
    ll sum(ll x) {
        ll ans = 0;
        for (ll i = x; i > 0; i -= (i & -i)) ans += bit[i];
        return ans;
    }
    ll query(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }
};
struct BIT2D {
    ll n, m;
    vector<vector<ll>> bit;
    BIT2D(ll _n, ll _m) : n(_n), m(_m), bit(n + 1, vector<ll>(m + 1)) { }
    void add(ll x, ll y, ll val) {
        for (ll i = x; i <= n; i += (i & -i)) {
            for (ll j = y; j <= m; j += (j & -j)) {
                bit[i][j] += val;
            }
        }
    }
    ll sum(ll x, ll y) {
        ll ans = 0;
        for (ll i = x; i > 0; i -= (i & -i)) {
            for (ll j = y; j > 0; j -= (j & -j)) {
                ans += bit[i][j];
            }
        }
        return ans;
    }
    ll query(ll x1, ll y1, ll x2, ll y2) {
        return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
    }
};