//__builtin_clz() -> number of leading 0bits from msb
//__builtin_ctz() -> number of leading 0bits from lsb
const int B = 25;
const int N = 1e5 + 10;
vector<int> a(N);
vector<vector<int>> t(B, vector<int> (N, 0));
void build(int n) {
    for (int i = 1; i <= n; ++i) t[0][i] = a[i];
    for (int j = 1; j < B; ++j) for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
        t[j][i] = __gcd(t[j - 1][i], t[j - 1][i + (1 << (j - 1))]);
    }
}
int query(int l, int r) {
    int lg = 31 - __builtin_clz(r - l + 1);
    return __gcd(t[lg][l], t[lg][r - (1 << lg) + 1]);
}
