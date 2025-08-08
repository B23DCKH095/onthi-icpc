#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct seg {
    ll ans, sum, pref, suff;
};

const int maxn = 1e5 + 10;
seg t[4*maxn];
ll lazy[4*maxn];
bool marked[4*maxn];

seg combine(seg a, seg b) {
    seg res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suff = max(b.suff, a.suff + b.sum);
    res.ans = max({a.ans, b.ans, a.suff + b.pref});
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {0, 0, 0, 0};
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
}

void push(int v, int tl, int tr) {
    if (marked[v]) {
        int tm = (tl + tr) / 2;
        
        // Left child
        ll val = lazy[v];
        ll left_len = tm - tl + 1;
        t[2*v].sum = val * left_len;
        t[2*v].pref = t[2*v].suff = t[2*v].ans = max(0LL, val * left_len);
        lazy[2*v] = val;
        marked[2*v] = true;
        
        // Right child
        ll right_len = tr - tm;
        t[2*v+1].sum = val * right_len;
        t[2*v+1].pref = t[2*v+1].suff = t[2*v+1].ans = max(0LL, val * right_len);
        lazy[2*v+1] = val;
        marked[2*v+1] = true;
        
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r) return;
    if (l == tl && r == tr) {
        t[v].sum = val * (r - l + 1);
        t[v].pref = t[v].suff = t[v].ans = max(0LL, val * (r - l + 1));
        lazy[v] = val;
        marked[v] = true;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, min(r, tm), val);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, val);
        t[v] = combine(t[2*v], t[2*v+1]);
    }
}

ll query() {
    return t[1].ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    build(1, 0, n-1);
    while (m--) {
        int l, r, v;
        cin >> l >> r >> v;
        update(1, 0, n-1, l, r-1, v);
        cout << query() << '\n';
    }
}