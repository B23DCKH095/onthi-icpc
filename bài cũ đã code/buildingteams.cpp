#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 +10;
vector<int> adj[maxn];
bool vis[maxn];
int color[maxn];

bool match = true;
void dfs(int x){
    vis[x] = true;
    for(int v : adj[x]){
        if(!vis[v]) {
            color[v] = 1- color[x];
            dfs(v);
        } else if(color[v] == color[x]){
            match = false;
        }
    }
    return;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0 ;i <m ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i =1 ; i<= n ;i++){
        if(!vis[i]){
            color[i] = 0;
            dfs(i);
        }
    }
    if(!match){
        cout <<"IMPOSSIBLE"<< endl;
        return 0;
    }
    else{
        for(int i =1 ;i <=n ; i++) cout << color[i]+1 << " ";
    }
}