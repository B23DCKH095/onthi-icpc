#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> adj[maxn];
bool vis[maxn];
int dp[maxn];
const int mod = 1e9 + 7;
vector<int> dag;

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
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    reverse(dag.begin() ,dag.end());
    dp[1] = 1;
    for(int u : dag){
        for(int v : adj[u]){
            dp[v] += dp[u];
            dp[v] %= mod;
        }
    }
    cout << dp[n]<< endl;
}