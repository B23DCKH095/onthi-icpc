#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};
 
struct LCA {
    int T = 0;
    vi time, path, ret;
    RMQ<int> rmq;
 
    LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vi>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v]) if (y != par) {
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v);
        }
    }
 
    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    
    vector<vi> tree(n);
    for(int i = 1; i < n; i++) {  // Bắt đầu từ 1 vì nút 0 là gốc
        int p;
        cin >> p;
        --p;  // Chuyển về 0-based
        tree[p].push_back(i);
        tree[i].push_back(p);
    }
    
    LCA lca(tree);
    
    while(q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;  // Chuyển về 0-based
        cout << lca.lca(u, v) + 1 << endl;  // Chuyển về 1-based khi in kết quả
    }
    
    return 0;
}
