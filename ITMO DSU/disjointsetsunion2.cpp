#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
// vector<int> sz[maxn], mn[maxn], mx[maxn], p[maxn], r[maxn];
vector<int> sz,mn,mx,p,r;
int get(int a) {
    return p[a] == a ? a : p[a] = get(p[a]); // Path compression
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if(a == b) return; // Already in same set
    if(r[a] == r[b]) r[a]++;
    if(r[a] < r[b]) {
        p[a] = b;
        sz[b] += sz[a];
        mn[b] = min(mn[a], mn[b]);
        mx[b] = max(mx[a], mx[b]);
    } else {
        p[b] = a;
        sz[a] += sz[b];
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    p.resize(n+1);
    mx.resize(n+1);
    mn.resize(n+1);
    r.assign(n+1,0);
    sz.assign(n+1,1);
    for(int i = 1; i <= n; i++) {
        p[i] = mn[i]  =mx[i] =  i;
    }
    while(m--) {
        string t;
        cin >> t;
        if(t[0] == 'u') {
            int a, b;
            cin >> a >> b;
            unite(a, b);
        } else {
            int x;
            cin >> x;
            int root = get(x);
            cout << mn[root] << " " << mx[root] << " " << sz[root] << '\n';
        }
    }
    return 0;
}