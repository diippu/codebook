const int B = 31;
using ll = long long;

struct node {
    int sz;
    node *nxt[2];

    node() {
        nxt[0] = nxt[1] = NULL;
        sz = 0;
    }   
} *root;

void del(node* cur) {
    for (int i = 0; i < 2; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
    delete(cur);
}

void insert(int val) {
    node *cur = root;
    cur -> sz++;

    for (int i = B - 1; i >= 0; --i) {
        int b = val >> i & 1;
        if(cur -> nxt[b] == NULL) cur -> nxt[b] = new node();

        cur  = cur -> nxt[b];
        cur -> sz++;
    }
}

void erase(int val) {
    node *cur = root;
    cur -> sz--;

    for (int i = B - 1; i >= 0; --i) {
        int b = val >> i & 1;
        node *tmp = cur;
        cur = cur -> nxt[b];
        cur -> sz--;
        if((cur -> sz) == 0) {
            del(cur);
            tmp -> nxt[b] = NULL; break;
        }
    }
}

int query_max(int val) { 
    //return maximum of val ^ x(x is inserted)
    int ans = 0;
    node *cur = root;

    for (int i = B - 1; i >= 0; --i) {
        int b = val >> i & 1;
        if(cur -> nxt[!b] != NULL) ans += (1 << i), cur = cur -> nxt[!b];
        else cur = cur -> nxt[b];
    }
    return ans;
}

int query_min(int val) { 
    ////return minimum of val ^ x(x is inserted)
    int ans = 0;
    node *cur = root;

    for (int i = B - 1; i >= 0; --i) {
        int b = val >> i & 1;
        if(cur -> nxt[b] != NULL) cur = cur -> nxt[b];
        else ans += (1 << i), cur = cur -> nxt[!b]; 
    }
    return ans;
}

int query(ll val, ll k) { 
    //return number of values x, val ^ x < k(x is inserted)
    int ans = 0;
    node *cur = root;
    for (ll i = B - 1; i >= 0; --i) {
        int bit1 = val >> i & 1;
        int bit2 = k >> i & 1;

        if(bit2 == 0) {
            if(cur -> nxt[bit1] != NULL) cur = cur -> nxt[bit1];
            else break;
        } else {
            if(cur -> nxt[bit1] != NULL) ans += (cur -> nxt[bit1]) -> sz;
            if(cur -> nxt[!bit1] != NULL) cur = cur -> nxt[!bit1];
            else break;
        }
    }
    return ans;
}
