#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
ll t[4*maxn], lazy[4*maxn];

void push(int v, int tl, int tr) {
    if(lazy[v] != 0) {
        int tm = (tl + tr) / 2;
        // Update left child
        lazy[2*v] += lazy[v];
        t[2*v] += lazy[v] * (tm - tl + 1);
        // Update right child
        lazy[2*v+1] += lazy[v];
        t[2*v+1] += lazy[v] * (tr - tm);
        // Reset current node
        lazy[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if(l > r) return;
    if(tl == l && tr == r) {
        t[v] += val * (tr - tl + 1);
        lazy[v] += val;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, min(r, tm), val);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, val);
        t[v] = t[2*v] + t[2*v+1];
    }
}

int get_first(int v, int tl, int tr, int l, ll x) {
    if(tr < l) return -1;  // Outside the search range
    if(tl == tr) {
        return (t[v] >= x) ? tl : -1;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    
    // First check if the left child has the answer
    if(tm >= l && t[2*v] >= x) {
        int left = get_first(2*v, tl, tm, l, x);
        if(left != -1) return left;
    }
    // Then check the right child if needed
    return get_first(2*v+1, tm+1, tr, l, x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    
    // Initialize the segment tree
    memset(t, 0, sizeof(t));
    memset(lazy, 0, sizeof(lazy));
    
    while(m--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            update(1, 0, n-1, l, r-1, u);
        } else {
            int x, l;
            cin >> x >> l;
            cout << get_first(1, 0, n-1, l, x) << '\n';
        }
    }
}