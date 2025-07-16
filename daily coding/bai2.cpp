#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<pair<int, int>> history;

void init(int n) {
    parent.assign(n, -1);
}

int find(int x) {
    return parent[x] < 0 ? x : find(parent[x]);
}

int snapshot() {
    return history.size();
}

void rollback(int t) {
    while (history.size() > t) {
        auto [x, px] = history.back();
        parent[x] = px;
        history.pop_back();
    }
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    
    if (parent[a] > parent[b]) swap(a, b);
    
    history.emplace_back(a, parent[a]);
    history.emplace_back(b, parent[b]);
    
    parent[a] += parent[b];
    parent[b] = a;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    init(n + 1);
    
    map<pair<int, int>, int> edge_snapshots;
    int components = n;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        
        if (unite(a, b)) {
            components--;
            edge_snapshots[{a, b}] = snapshot();
        }
    }
    
    cout << components << " ";
    
    vector<pair<int, int>> active_edges;
    for (int i = 0; i < k; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (a > b) swap(a, b);
        
        if (t == 1) {
            if (unite(a, b)) {
                components--;
                edge_snapshots[{a, b}] = snapshot();
            } else {
                active_edges.emplace_back(a, b);
            }
        } else {
            if (edge_snapshots.count({a, b})) {
                int snap_time = edge_snapshots[{a, b}];
                edge_snapshots.erase({a, b});
                
                int current_time = snapshot();
                rollback(snap_time);
                
                vector<pair<int, int>> new_active;
                for (auto& edge : active_edges) {
                    if (unite(edge.first, edge.second)) {
                        components--;
                        edge_snapshots[edge] = snapshot();
                    } else {
                        new_active.push_back(edge);
                    }
                }
                active_edges = move(new_active);
                
                if (find(a) != find(b)) {
                    components++;
                }
                
                rollback(current_time);
            }
        }
        
        cout << components << " ";
    }
    
    return 0;
}