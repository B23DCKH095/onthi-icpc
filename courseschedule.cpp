#include <bits/stdc++.h>
using namespace std;

vector<int> dag;
vector<int> tmp;
const int maxn =1e5 + 10;
vector<int> adj[maxn];
bool vis[maxn];
int idx[maxn];
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    dag.push_back(u);
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0 ;i < m ;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i =1; i<= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(dag.begin() ,dag.end());
    int cnt = 0;
    for(int v : dag){
        idx[v] = cnt;
        ++ cnt;
    }
    bool ok = true;
    for(int u : dag){
        for(int v : adj[u]){
            if(idx[u] >= idx[v]){
                cout <<"IMPOSSIBLE"<< endl;
                return 0;
            }
        }
    }
    if(dag.size() != n) cout <<"IMPOSSIBLE"<< endl;
    else {
        for(int u : dag) cout << u << " ";
    }
}