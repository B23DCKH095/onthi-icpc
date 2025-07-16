#include <bits/stdc++.h>
using namespace std;

const int maxn =1e5  +10;
vector<int> adj[maxn];
int dp[maxn];
bool vis[maxn];
vector<int> dag;

void dfs(int x){
    vis[x] = true;
    for(int v : adj[x]){
        if(!vis[v]) dfs(v);
    }
    dag.push_back(x);
}

int main(){
    freopen("timeline.in","r",stdin);
    freopen("timeline.out","w",stdout);
    int n,m,c;
    cin >> n >> m >> c;
    for(int i =1; i <= n ;i++){
        int x;
        cin >> x;
        adj[i].push_back(x);
    }
    for(int i =1; i<= n ;i++){
        if(!vis[i]) dfs(i);
    }
    int cnt = 0;
    for(int u : dag){
        dp[u] = ++ cnt;
    }
    for(int i = 0 ; i< c; i++){
        int a,b,w;
        bool ok = true;
        cin >> a >> b >> w;
        int tmp = dp[a] + w;
        if(tmp > m) continue;
        for(int v : adj[b]){
            if(dp[v] >= tmp) {
                ok = false;
                break;
            }
        }
        if(ok) dp[b] = tmp;
    }
    for(int i =1; i<= n ;i++) cout << dp[i] << endl;
}