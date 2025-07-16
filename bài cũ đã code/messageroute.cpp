#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
bool vis[maxn];
int p[maxn];
vector<int> adj[maxn];

void dfs(int u){
    vis[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int v : adj[x]){
            if(!vis[v]) {
                p[v] = x;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0 ;i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    if(!vis[n]) cout <<"IMPOSSIBLE"<< endl;
    else{
        int u = 1 , v = n;
        vector<int> ans;
        while(u != v){
            ans.push_back(v);
            v = p[v];
        }
        ans.push_back(1);
        reverse(ans.begin() ,ans.end());
        cout << ans.size() << endl;
        for(int i : ans) cout << i <<" ";
    }
}