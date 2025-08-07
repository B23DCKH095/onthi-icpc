#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
ll t[4*maxn];       // Segment tree nodes
ll lazy[4*maxn];    // Lazy propagation values

void build(int v, int tl, int tr) {
    lazy[v] = 1;    // Initialize lazy value
    if(tl == tr) {
        t[v] = 1;   // Initialize leaf nodes to 1
    } else {
        int tm = tl + (tr-tl)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = (t[2*v] + t[2*v+1]) % mod;  // Sum of children
    }
}

void push(int v, int tl, int tr) {
    if(lazy[v] != 1) {  // Only push if there's something to propagate
        int tm = tl + (tr-tl)/2;
        
        // Apply to left child
        t[2*v] = (t[2*v] * lazy[v]) % mod;
        lazy[2*v] = (lazy[2*v] * lazy[v]) % mod;
        
        // Apply to right child
        t[2*v+1] = (t[2*v+1] * lazy[v]) % mod;
        lazy[2*v+1] = (lazy[2*v+1] * lazy[v]) % mod;
        
        lazy[v] = 1;    // Reset current node's lazy value
    }
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if(l > r) return;
    if(tl == l && tr == r) {
        t[v] = (t[v] * val) % mod;
        lazy[v] = (lazy[v] * val) % mod;
    } else {
        push(v, tl, tr);
        int tm = tl + (tr-tl)/2;
        update(2*v, tl, tm, l, min(r, tm), val);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, val);
        t[v] = (t[2*v] + t[2*v+1]) % mod;  // Update current node's sum
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;  // Return 0 for sum queries
    if(tl == l && tr == r) {
        return t[v];
    }
    push(v, tl, tr);
    int tm = tl + (tr-tl)/2;
    ll left = query(2*v, tl, tm, l, min(r, tm));
    ll right = query(2*v+1, tm+1, tr, max(l, tm+1), r);
    return (left + right) % mod;  // Sum of children
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    build(1, 0, n-1);
    while(m--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            update(1, 0, n-1, l, r-1, u);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n-1, l, r-1) << endl;
        }
    }
    return 0;
}