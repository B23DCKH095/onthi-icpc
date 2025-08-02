#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 2e5 + 10;
set<int> color[maxn];
vector<int> distinct(maxn) ,adj[maxn];

void dfs(int u, int parent) {
    for(int v : adj[u]) {
        if(v != parent) {
            dfs(v, u);
            // Small-to-large merging
            if(color[u].size() < color[v].size()) {
                swap(color[u], color[v]);
            }
            for(int x : color[v]) {
                color[u].insert(x);
            }
            color[v].clear(); // Giải phóng bộ nhớ
        }
    }
    distinct[u] = color[u].size();
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     for(int i = 1; i<= n ; i++){
        int x;
        cin >> x;
        color[i].insert(x);
     }
     for(int i = 0 ; i<n-1; i ++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
     }
     dfs(1,0);
     for(int i = 1 ;i<= n ; i++) cout << distinct[i] <<" ";
}