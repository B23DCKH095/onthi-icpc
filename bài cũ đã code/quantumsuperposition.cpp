#include <bits/stdc++.h>
using namespace std;

vector<int> dag;
const int maxn = 2010;
vector<int> adj[maxn];
bool vis[maxn];
set<int> dp[maxn];  // Lưu các độ dài đường đi từ nguồn tới u

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
    dag.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2, m1, m2;
    cin >> n1 >> n2 >> m1 >> m2;

    // Xử lý đồ thị 1
    int n = n1, m = m1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);
    reverse(dag.begin(), dag.end());
    dp[1].insert(0);  // Độ dài 0 khi bắt đầu từ đỉnh 1

    for (int u : dag) {
        for (int v : adj[u]) {
            for (int len : dp[u]) {
                dp[v].insert(len + 1);  // Thêm độ dài mới
            }
        }
    }
    set<int> lengths1 = dp[n1];  // Lưu các độ dài từ 1 -> n1
    dag.clear();
    memset(vis, 0, sizeof(vis));
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < maxn; i++) dp[i].clear();

    // Xử lý đồ thị 2
    n = n2, m = m2;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);
    reverse(dag.begin(), dag.end());
    dp[1].insert(0);  // Độ dài 0 khi bắt đầu từ đỉnh 1

    for (int u : dag) {
        for (int v : adj[u]) {
            for (int len : dp[u]) {
                dp[v].insert(len + 1);  // Thêm độ dài mới
            }
        }
    }
    set<int> lengths2 = dp[n2];  // Lưu các độ dài từ 1 -> n2

    // Kết hợp các độ dài từ 2 đồ thị
    set<int> total;
    for (int len1 : lengths1) {
        for (int len2 : lengths2) {
            total.insert(len1 + len2);
        }
    }

    // Xử lý truy vấn
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << (total.count(x) ? "Yes" : "No") << '\n';
    }

    return 0;
}