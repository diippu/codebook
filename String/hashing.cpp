const int N = 2e5 + 10;
vector<int> p1(N, 1), p2(N, 1);
vector<int> inp1(N, 1), inp2(N, 1);
int b1 = 37, m1 = 1e9 + 7;
int b2 = 73, m2 = 998244341;
int modp(int i, int j, int m) {
    return 1ll * i * j % m;
}
int moda(int i, int j, int m) {
    return (i + j) % m;
}
int mods(int i, int j, int m) {
    return ((i - j) % m + m) % m;
}
vector<int> get_hash(string s, int b, int m, vector<int> &p) {
    //hash vector of a string 1000456781 998244341 37 73
    int sz = s.size();
    s = '#' + s;//everything is 1 based indexing
    vector<int> hash(sz + 10);
    hash[0] = 0;
    hash[1] = (s[1] - 'a' + 1);
    for (int i = 1; i <= sz; i++) {
        int cur = modp(s[i] - 'a' + 1, p[i], m);
        hash[i] = moda(hash[i - 1], cur, m) % m;
    }
    return hash;
}
int getHashL_R(int l, int r, vector<int> &hash, vector<int> &inp, int m) {
     int hsh = mods(hash[r], hash[l - 1], m);
     hsh = modp(hsh, inp[l], m);
     return hsh;
}
int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1) res = 1ll * res * a % m;
        a = 1ll * a * a % m;
        b >>= 1;
    }
    return res % m;
}
void pre() {
    //p[i] have power i - 1;
    for (int i = 2; i < N; i++) {
        p1[i] = modp(p1[i - 1], b1, m1);
        p2[i] = modp(p2[i - 1], b2, m2);
        inp1[i] = binpow(p1[i], m1 - 2, m1);
        inp2[i] = binpow(p2[i], m2 - 2, m2);
    }
}
