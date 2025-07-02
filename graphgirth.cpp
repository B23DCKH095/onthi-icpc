#include <bits/stdc++.h>
using namespace std;

const int maxn =2510;
vector<int> adj[maxn];
bool vis[maxn];
int d[maxn];
vector<pair<int,int>> edges;

// void dfs(int u,int p){
//     vis[u] = true;
//     for(int v : adj[u]){
//         if(v==p) continue;
//         if(!vis[v]) dfs(v,u);
//         else ok = true;
//     }
// }
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i< m ;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a,b});
    }
    for(int i =1; i<= n ;i++) d[i] = 1e9;
    d[1]= 0;
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!vis[v]){
                d[v] = d[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    int mn = 1e9;
    for(pair<int,int> u : edges){
        int a = u.first;
        int b = u.second;
        if(a != 1 && b != 1) mn = min(mn ,d[a] + d[b]);
    }
    cout << mn << endl;
}