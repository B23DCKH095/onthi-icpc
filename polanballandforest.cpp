#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool vis[100001];
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]) dfs(v);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin>> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    int cnt =0;
    for(int i =1; i<= n; i++){
        if(!vis[i]){
            ++ cnt;
            dfs(i);
        }
    }
    cout << cnt << endl;
}