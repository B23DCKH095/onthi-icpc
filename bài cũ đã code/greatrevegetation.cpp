#include <bits/stdc++.h>
using namespace std;

const int maxn =2e5 + 10;
bool color[maxn];
vector<pair<int,char>> adj[maxn];
bool cant = false;
bool vis[maxn];
void dfs(int u){
    vis[u] = true;
    for(auto vv : adj[u]){
        int v = vv.first;
        char c = vv.second;
        if(!vis[v]){
            if(c=='S') color[v] = color[u];
            else color[v] = 1- color[u];
            dfs(v);
        } else{
            if(c== 'D' && color[u] == color[v]) cant = true;
            if(c=='S' && color[u] != color[v]) cant = true;
        }
    }
    return;
}
vector<int> ans;
void nhiphan(int n){
    while(n){
        int tmp = n%2;
        ans.push_back(tmp);
        n/=2;
    }
    reverse(ans.begin() , ans.end());
}
int main(){
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    int n,m;
    cin >> n >>m;
    for(int i = 0 ; i<m ; i++){
        char c;
        int a , b;
        cin >> c >> a >> b;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int dem = 0;
    for(int i = 1; i <=n ; i++){
        if(!vis[i]){
            color[i] =0;
            ++ dem;
            dfs(i);
        }
    }
    if(cant) {
        cout << 0 << endl;
        return 0;
    }
    ans.push_back(1);
    for(int i = 0 ; i <dem ; i++) ans.push_back(0);

    for(int v : ans) cout << v;
}