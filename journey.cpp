#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> adj[maxn];
int cnt[maxn];

vector<int> leaf;
void dfs(int u,int p){
    for(int v : adj[u]){
        if(v == p) continue;
        cnt[v] = cnt[u]+1;
        dfs(v,u);
    }
    
}
int main(){
    int n;
    cin >> n;
    for(int i= 0; i <n -1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(int i = 1; i<= n ;i++){
        if(adj[i].size() == 1)leaf.push_back(i);
    }
    int ans = 0;
    for(int v : leaf) ans += cnt[v];
    double s = ans/leaf.size() + 1;
    cout << fixed << setprecision(13)<< s << endl;
}