#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> adj[maxn];
char c[maxn];
bool vis[maxn];
int lt[maxn];
int color;
void dfs(int x){
    vis[x] = true;
    lt[x]  =color;
    for(int v : adj[x]){
        if(!vis[v] && c[x] == c[v]) dfs(v);
    }
}

int main(){
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i =1; i <= n ;i++) cin >> c[i];
    for(int i = 0 ;i < n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i =1; i<= n ;i++){
        if(!vis[i]){
            ++ color;
            dfs(i);
        }
    }
    for(int i = 0 ;i < m; i++){
        int a,b;
        char co;
        cin >> a >> b >> co;
        bool ok = false;
        if(lt[a] != lt[b]) ok = true;
        if(lt[a] == lt[b] && co == c[a]) ok = true;
        if(ok) cout << 1 ;
        else cout << 0 ;
    }

}