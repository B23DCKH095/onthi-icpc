#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v, adj, visited, st);
        }
    }
    st.push(u);
}

void dfs2(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs2(v, adj, visited, component);
        }
    }
}

vector<vector<int>> findSCCs(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;
    

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }
    

    vector<vector<int>> reversed_adj(n);
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            reversed_adj[v].push_back(u);
        }
    }
    

    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        
        if (!visited[u]) {
            vector<int> component;
            dfs2(u, reversed_adj, visited, component);
            sccs.push_back(component);
        }
    }
    
    return sccs;
}
bool r[1001];
int main() {
    int n, m; 
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u,v,su,sv;
        cin >> u >> v >> su >> sv;
        --u,--v;
        if(su > sv) adj[u].push_back(v);
        else adj[v].push_back(u);
    }
    
    vector<vector<int>> sccs = findSCCs(n, adj);
    

    for (const auto& component : sccs) {
        if(component.size() == 1) continue;
        for(int v : component) cout << v+1 <<' ';
        cout << endl;
    }
    int cnt = 0;
    for(int i = 0 ; i< n; i++) cnt += r[i];
    cout << cnt << endl;
    
    return 0;
}