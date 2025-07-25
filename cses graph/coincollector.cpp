#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 10;

bool vis[maxn];
vector<int> adj[maxn], rev_adj[maxn];
stack<int> st;

void dfs(int u) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
    st.push(u);
}

vector<int> arr;
void dfs2(int u) {
    vis[u] = true;
    arr.push_back(u);
    for(int v : rev_adj[u]) {
        if(!vis[v]) dfs2(v);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    vector<int> val(n+1);
    for(int i = 1; i <= n; i++) cin >> val[i];
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    
    // First pass: fill the stack with nodes in order of finishing times
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    
    // Second pass: find SCCs
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    vector<int> planet(n+1);
    vector<ll> component_val;
    vector<vector<int>> components;
    
    while(!st.empty()) {
        int x = st.top();
        st.pop();
        if(!vis[x]) {
            arr.clear();
            dfs2(x);
            cnt++;
            ll sum = 0;
            for(int u : arr) {
                planet[u] = cnt;
                sum += val[u];
            }
            component_val.push_back(sum);
            components.push_back(arr);
        }
    }
    
    // Build component graph
    vector<vector<int>> component_adj(cnt+1);
    vector<int> in_degree(cnt+1, 0);
    
    for(int u = 1; u <= n; u++) {
        for(int v : adj[u]) {
            if(planet[u] != planet[v]) {
                component_adj[planet[u]].push_back(planet[v]);
                in_degree[planet[v]]++;
            }
        }
    }
    
    // Topological sort using Kahn's algorithm
    queue<int> q;
    vector<ll> max_val(cnt+1, 0);
    
    for(int i = 1; i <= cnt; i++) {
        max_val[i] = component_val[i-1]; // components are 1-based
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : component_adj[u]) {
            if(max_val[v] < max_val[u] + component_val[v-1]) {
                max_val[v] = max_val[u] + component_val[v-1];
            }
            in_degree[v]--;
            if(in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    
    ll mx = *max_element(max_val.begin()+1, max_val.end());
    cout << mx << endl;
    
    return 0;
}