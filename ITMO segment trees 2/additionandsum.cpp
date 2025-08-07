#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
ll t[4 * maxn], lazy[4 * maxn];

void build(int v, int tl, int tr) {
    lazy[v] = 0;
    if (tl == tr) {
        t[v] = 0;  // Initialize to 0
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = t[2*v] + t[2*v+1];  // Initialize sum
    }
}

void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
        int tm = (tl + tr) / 2;
        // Update left child
        t[2*v] += lazy[v] * (tm - tl + 1);
        lazy[2*v] += lazy[v];
        // Update right child
        t[2*v+1] += lazy[v] * (tr - tm);
        lazy[2*v+1] += lazy[v];
        // Reset current lazy value
        lazy[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (tl == l && tr == r) {
        t[v] += (ll)val * (r - l + 1);  // Update sum
        lazy[v] += val;                  // Mark lazy update
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, min(r, tm), val);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, val);
        t[v] = t[2*v] + t[2*v+1];  // Update current node's sum
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(2*v, tl, tm, l, min(r, tm)) + 
           query(2*v+1, tm+1, tr, max(l, tm+1), r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    build(1, 0, n-1);  // Initialize the segment tree
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            update(1, 0, n-1, l, r-1, u);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n-1, l, r-1) << '\n';
        }
    }
    return 0;
}