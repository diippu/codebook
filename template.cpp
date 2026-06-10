#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = array<int, 2>;
using tup = array<int, 3>;
using LL = __int128;
template <typename T>
using order_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
//find_by_order() -> iterator to the k-th largest element (zero based)
//order_of_key() -> the number of items that are strictly smaller 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(int tc) {
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, tc = 0; cin >> t;
    while (t--) solve(++tc); 
}
