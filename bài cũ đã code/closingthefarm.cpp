#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 2e5 + 10;
bool vis[maxn];
vector<int> adj[maxn];
bool close[maxn];
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v] && !close[v]) dfs(v);
    }
}
int dem(){
    int cnt = 0;
    for(int i = 1 ; i<= n ; i++){
        if(!vis[i] && !close[i]) {
            ++ cnt;
            dfs(i);
        }
    }
    return cnt;
}
int x;
bool tru[maxn];
int main(){
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    int m;
    cin >> n >> m;
    for(int i = 0 ;i < m ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int tplt = dem();
    vector<int> a(n);
    for(int i = 0 ;i < n ; i++) cin >> a[i];
    if(tplt == 1) cout <<"YES" << endl;
    else cout <<"NO"<< endl;
    for(int i = 0; i < n-1 ;i++){
        memset(vis,0,sizeof(vis));
        close[a[i]] = true;
        tplt = dem();
        if(tplt == 1) cout << "YES"  << endl;
        else cout <<"NO"<< endl;
    }
}