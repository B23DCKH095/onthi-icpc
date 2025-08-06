#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct seg {
    ll pref, suff, ans, sum;
};

seg combine(seg left, seg right) {
    seg res;
    res.sum = left.sum + right.sum;
    res.pref = max(left.pref, left.sum + right.pref);
    res.suff = max(right.suff, left.suff + right.sum);
    res.ans = max({left.ans, right.ans, left.suff + right.pref});
    return res;
}

seg make_data(ll val) {  // Changed to ll to match the type of 'val'
    seg res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0LL, val);  // Using 0LL for type consistency
    return res;
}

const int maxn = 1e5 + 10;
seg t[4 * maxn];

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_data(a[tl]);
    } else {
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }
}

void update(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
        t[v] = make_data(val);
    } else {
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }
}

ll query() {  // Changed return type to ll to match the data type
    return t[1].ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    build(a, 1, 0, n - 1);
    cout << query() << "\n";  // Using "\n" instead of endl for faster output
    
    while (q--) {
        int i;
        ll v;
        cin >> i >> v;
        update(1, 0, n - 1, i, v);  // Assuming 0-based indexing
        cout << query() << "\n";
    }
    
    return 0;
}