#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> adj[maxn];
bool vis[maxn];
int cnt[maxn];

void dfs(int u,int p){
    cnt[u] = 1;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v,u);
        cnt[u] += cnt[v];
    }
}
int main(){
    int n;
    cin >> n;
    for(int i =2; i<= n ;i++){
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(1,-1);
    for(int i =1; i <= n ;i++) cout << cnt[i]-1 <<' ';
}