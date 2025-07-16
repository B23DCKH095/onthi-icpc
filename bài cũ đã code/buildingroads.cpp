#include <bits/stdc++.h>
using namespace std;

bool vis[200001];
vector<int> adj[200001];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]) dfs(v);
    }
    return;
}
int main(){
    int n,m;
    cin >> n >>m;
    vector<int> roads;
    roads.clear();
    for(int i = 0; i <m ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1 ;i <=n ; i++){
        if(!vis[i]){
            roads.push_back(i);
            dfs(i);
        }
    }
    cout << roads.size() -1 << endl;
    for(int v : roads) {
        if(v != 1) cout << 1 <<" "<< v << endl;
    }
}