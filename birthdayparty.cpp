#include <bits/stdc++.h>
using namespace std;

const int maxn =5001;
int n;
int a[maxn][maxn];
bool vis[maxn];
void dfs(int u){
    vis[u] =true;
    for(int v = 0 ;v < n ;v ++){
        if(!vis[v] && a[u][v]) dfs(v);
    }
}
bool checklt(){
    memset(vis,0,sizeof(vis));
    dfs(0);
    for(int i = 0 ; i <n ; i++){
        if(!vis[i]) return false;
    }
    return true;
}
int main(){
    int m;
    while(cin >> n >> m){
        bool ok = false;
        if(n==0 && m == 0) return 0;
        vector<pair<int,int>> edges;
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        for(int i = 0 ;i < m; i++){
            int x,y;
            cin >> x >> y;
            edges.push_back({x,y});
            a[x][y] = a[y][x] = 1;
        }
        for(int i = 0 ; i< m ; i++){
            pair<int,int> u = edges[i];
            int x = u.first;
            int y = u.second;
            a[x][y] = a[y][x] = 0;
            if(!checklt()){
                ok = true;
                break;
            }
            a[x][y] = a[y][x] = 1;
        }
        if(!ok) cout <<"No"<< endl;
        else cout <<"Yes"<< endl;

    }
}