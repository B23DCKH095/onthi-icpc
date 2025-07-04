#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn =2e5 + 10;
ll val[maxn],d[maxn],p[maxn];
vector<int> adj[maxn];
void dfs(int u,int par){
    d[u] = val[u];
    for(int v : adj[u]){
        if(v==par) continue;
        p[v] = u;
        dfs(v,u);
        d[u] += d[v];
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n ;i++){
        int x;
        cin >> x;
        val[i] = x;
    }
    for(int i = 0 ; i < n-1 ; i++){
        int a,b;
        cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    for(int i = 0 ;i < m ;i ++){
        int t;
        cin >> t;
        if(t==1){
            int s,x;
            cin >>s >> x;
            val[s] =x;
        }
        else {
            int s;
            cin >> s;
            dfs(s,p[s]);
            cout << d[s]<< endl;
        }
    }
}