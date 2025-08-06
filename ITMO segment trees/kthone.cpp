#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
int n, t[4*maxn];
int a[maxn];

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = tl + (tr-tl)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v] = t[2*v] + t[2*v+1];
    }
}

int query(int v, int tl, int tr, int k) {
    if(k > t[v]) return -1;
    if(tl == tr) return tl;
    int tm = tl + (tr-tl)/2;
    if(k <= t[2*v]) {
        return query(2*v, tl, tm, k);
    } else {
        return query(2*v+1, tm+1, tr, k - t[2*v]);
    }
}

void update(int v, int tl, int tr, int pos) {
    if(tl == tr) {
        t[v] = a[tl];  // Directly set to current value of a[pos]
    } else {
        int tm = tl + (tr-tl)/2;
        if(pos <= tm) {
            update(2*v, tl, tm, pos);
        } else {
            update(2*v+1, tm+1, tr, pos);
        }
        t[v] = t[2*v] + t[2*v+1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(a, 1, 0, n-1);
    
    while(q--) {
        int type, r;
        cin >> type >> r;
        if(type == 1) {
            a[r] = 1 - a[r];  // Toggle the value first
            update(1, 0, n-1, r);  // Then update the segment tree
        } else {
            cout << query(1, 0, n-1, r+1) << endl;  // r+1 because we want the k-th 1 (1-based)
        }
    }
    return 0;
}