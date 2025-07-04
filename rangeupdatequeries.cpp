#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
ll tree[maxn], a[maxn];
int n;

ll sum(int k) {
    ll s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

void add(int k, int x) {
    while (k <= n) {
        tree[k] += x;
        k += k & -k;
    }
}

int main() {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i,a[i] - a[i-1]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v, x;
            cin >> u >> v >> x;
            add(u, x);
            add(v+1,-x);
        }
        else {
            int k;
            cin >> k;
            cout << sum(k) << endl;
        }
    }
}