#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
int t[4*maxn];       // stores the count of 1's in the segment
bool marked[4*maxn];  // marks whether a segment needs to be flipped

void push(int v, int tl, int tr) {
    if (marked[v]) {
        marked[v] = false;
        int tm = (tl + tr) / 2;
        
        // Flip left child
        marked[2*v] = !marked[2*v];
        t[2*v] = (tm - tl + 1) - t[2*v];
        
        // Flip right child
        marked[2*v+1] = !marked[2*v+1];
        t[2*v+1] = (tr - tm) - t[2*v+1];
    }
}

void update(int v, int tl, int tr, int l, int r) {
    if (l > r) return;
    if (l == tl && r == tr) {
        // Flip the current segment
        t[v] = (tr - tl + 1) - t[v];
        marked[v] = !marked[v];
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, min(r, tm));
        update(2*v+1, tm+1, tr, max(l, tm+1), r);
        t[v] = t[2*v] + t[2*v+1];
    }
}

int query(int v, int tl, int tr, int k) {
    if (t[v] < k) return -1;
    if (tl == tr) return tl;
    
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    
    if (t[2*v] >= k) {
        return query(2*v, tl, tm, k);
    } else {
        return query(2*v+1, tm+1, tr, k - t[2*v]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    
    // Initialize the segment tree (all bits are 0 initially)
    memset(t, 0, sizeof(t));
    memset(marked, false, sizeof(marked));
    
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            update(1, 0, n-1, l, r-1);
        } else {
            int k;
            cin >> k;
            cout << query(1, 0, n-1, k+1) << '\n';  // k+1 because we want the k-th 1 (1-based)
        }
    }
}