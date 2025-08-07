#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
int t[4*maxn], lazy[4*maxn];
bool marked[4*maxn];
const int INF = INT_MAX;


void push(int v) {
    if(marked[v]) {
        t[2*v] = lazy[v];
        t[2*v+1] = lazy[v];
        lazy[2*v] = lazy[v];
        lazy[2*v+1] = lazy[v];
        marked[2*v] = true;
        marked[2*v+1] = true;
        marked[v] = false;
        lazy[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if(l > r) return;
    if(tl == l && tr == r) {
        t[v] = val;
        lazy[v] = val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, min(r, tm), val);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, val);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return INF;
    if(tl == l && tr == r) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(2*v, tl, tm, l, min(r, tm)),
           query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    
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
            cout << query(1, 0, n-1, l, r-1) << '\n';
        }
    }
    return 0;
}