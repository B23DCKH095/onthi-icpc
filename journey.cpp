#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> adj[maxn];
double d[maxn],c[maxn];
double s ;
void dem(int u,int p){
    for(int v : adj[u]){
        if(v == p) continue;
        ++ c[u];
        dem(v,u);
    }
}
void dfs(int u,int p){
    if(p != -1) {
        d[u] = d[p]/c[p];
    }
    bool ok = false;
    for(int v : adj[u]){
        if(v == p) continue;
        ok = true;
        dfs(v,u);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i <n-1 ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dem(1,-1);
    d[1] = 1;
    dfs(1,-1);
    for(int i =2 ; i <= n ;i++) s += d[i];
    cout << fixed << setprecision(10)<< s << endl;
}