#include <bits/stdc++.h>
using namespace std;

const int maxn = 5001;
bool vis[maxn];
vector<pair<int,int>> adj[maxn];

int cnt = 0;

void dfs(int u,int p,int k){
    vis[u] = true;
    ++ cnt;
    for(pair<int,int> vv : adj[u]){

        int v = vv.first;
        int w = vv.second;
        if(v == p) continue;
        if(w >= k && !vis[v]){
            dfs(v,u,k);
        }
    }
}
int main(){
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i = 0 ;i < n-1; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        cnt = 0;
        int k,st;
        cin >> k >> st;
        dfs(st,-1,k);
        cout << cnt-1 << endl;
    }
}