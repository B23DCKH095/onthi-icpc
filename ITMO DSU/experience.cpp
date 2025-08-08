#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
vector<ll> point;
vector<int> p;
vector<unordered_set<int>> l;

int get(int a) {
    if (p[a] == a) return a;
    return p[a] = get(p[a]);
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (sz(l[a]) > sz(l[b])) swap(a, b);
    for (int x : l[a]) {
        p[x] = b;
        l[b].insert(x);
    }
    l[a].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    p.resize(n + 1);
    point.resize(n + 1, 0);
    l.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        l[i] = {i};
    }
    while (m--) {
        string t;
        cin >> t;
        if (t == "add") {
            int a, x;
            cin >> a >> x;
            int root = get(a);
            for (int u : l[root]) {
                point[u] += x;
            }
        } else if (t == "join") {
            int a, b;
            cin >> a >> b;
            unite(a, b);
        } else if (t == "get") {
            int a;
            cin >> a;
            cout << point[a] << '\n';
        }
    }
    return 0;
}