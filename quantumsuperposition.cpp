#include <bits/stdc++.h>
using namespace std;

vector<int> dag;
const int maxn = 2010;
vector<int> adj[maxn];
bool vis[maxn];
int dp[maxn];
bool ans[maxn];
void dfs(int u){
    vis[u] = true;
    for(int v: adj[u]){
        if(!vis[v]) dfs(v);
    }
    dag.push_back(u);
}
vector<int> v1,v2;
int main(){
    int n1,n2,m1,m2;
    cin >> n1 >> n2 >> m1 >> m2;
    int n,m;
    n = n1 , m = m1;
    for(int i = 0 ; i< m ;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    dp[1] = 1;
    reverse(dag.begin() , dag.end());
    for(int u : dag){
        for(int v : adj[u]){
            dp[v] += dp[u];
            if(v==n) v1.push_back(dp[v]);
        }
    }
    dag.clear();
    memset(vis,0,sizeof(vis));
    memset(adj,0,sizeof(adj));
    memset(dp,0,sizeof(dp));
    n = n2,m = m2;
    for(int i = 0 ; i< m ;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    dp[1] = 1;
    reverse(dag.begin() , dag.end());
    for(int u : dag){
        for(int v : adj[u]){
            dp[v] += dp[u];
            if(v==n) v2.push_back(dp[v]);
        }
    }
    set<int> se;
    for(int u : v1){
        for(int v : v2){
            se.insert(u + v);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(se.count(x)) cout <<"Yes"<< endl;
        else cout <<"No"<< endl;
    }
}