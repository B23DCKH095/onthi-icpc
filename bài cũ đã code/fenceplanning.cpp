#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
pair<int,int> a[maxn];
vector<int> adj[maxn];
vector<vector<int>> tplt;
bool vis[maxn];
vector<int> lt;
void dfs(int u){
    vis[u] = true;
    lt.push_back(u);
    for(int v : adj[u]){
        if(!vis[v]) dfs(v);
    }
    return;
}
int main(){
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    int n,m;
    cin >> n >>m;
    for(int i = 0 ; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 0 ; i< m ; i++){
        int x,y;
        cin >> x >> y;
        --x,--y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 0 ; i< n ;i++){
        if(!vis[i]) {
            lt.clear();
            dfs(i);
            tplt.push_back(lt);
        }
    }
    int mn  = 1e9;
    for(vector<int> u :tplt ){
        int xmax = 0 , ymax= 0,xmin = 1e9 , ymin = 1e9;
        for(int v : u){
            pair<int,int> x = a[v];
            xmax = max(xmax,x.first);
            xmin = min(xmin,x.first);
            ymax = max(ymax,x.second);
            ymin = min(ymin, x.second);
        }
        mn = min (mn , (xmax - xmin) + (ymax - ymin));
    }
    cout << mn*2 << endl;
}