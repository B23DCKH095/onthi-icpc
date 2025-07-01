#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> adj[maxn];
bool vis[maxn];
int p[maxn];
int dp[maxn];
vector<int> dag;

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]) {
            p[v] = u;
            dfs(v);
        }
    }
    dag.push_back(u);
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0 ;i < m ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    if(!vis[n]){
        cout <<"IMPOSSIBLE" << endl;
        return 0;
    }
    reverse(dag.begin() , dag.end());
    for(int u : dag){
        for(int v : adj[u]){
            if(dp[v] < dp[u]+1){
                dp[v] = dp[u]+1;
                p[v] = u;
            }
        }
    }
    int st = 1,en = n;
    vector<int> ans;
    while(st != en){
        ans.push_back(en);
        en = p[en];
    }
    ans.push_back(en);
    cout << ans.size()<< endl;
    reverse(ans.begin() , ans.end());
    for(int v : ans ) cout << v <<" ";
}