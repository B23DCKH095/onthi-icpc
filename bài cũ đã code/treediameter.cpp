#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int d[maxn];
vector<int> adj[maxn];

void dfs(int u,int p){
    if(p != -1) d[u] = d[p]  +1;
    for(int v : adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i< n-1 ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    int st = -1,mx = -1;
    for(int i =1; i<= n ;i++){
        if(d[i] > mx){
            mx = d[i];
            st = i;
        }
    }
    memset(d,0,sizeof(d));
    dfs(st,-1);
    mx = -1;
    for(int i = 1; i <= n ;i++) mx = max(mx,d[i]);
    cout << mx << endl;
}