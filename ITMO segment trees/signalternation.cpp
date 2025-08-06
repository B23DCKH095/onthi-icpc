#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
ll t[4 * maxn];
ll n;  

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];
    int tm = tl + (tr - tl) / 2;
    return sum(2 * v, tl, tm, l, min(r, tm)) 
         + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm) {
            update(2 * v, tl, tm, pos, val);
        } else {
            update(2 * v + 1, tm + 1, tr, pos, val);
        }
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int q;
    cin >> n ;
    ll a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(i%2== 1) a[i] *= -1;
    }
    
    build(a, 1, 0, n - 1);  // Correct range: [0, n-1]
    cin >> q;
    while (q--) {
        int t,u,v;
        cin >> t >> u >> v;
        --u,--v;
        
        if(t==0){
            ++v;
            if(u % 2 == 1) update(1,0,n-1,u,-v);
            else update(1,0,n-1,u,v);
        }
        else {
            int d ;
            if(u%2 == 1) d = -1;
            else d = 1;
            cout << d*sum(1,0,n-1,u,v) << endl;
        }
    }
}