#include <bits/stdc++.h>
using namespace std;

vector<int> dag;
vector<int> tmp;
const int maxn =1e5 + 10;
vector<int> adj[maxn];
bool vis[maxn];
int idx[maxn];
int p[maxn];
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
            p[v] = u;
        }
    }
    dag.push_back(u);
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0 ;i < m ;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i =1; i<= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(dag.begin() ,dag.end());
    int cnt = 0;
    for(int v : dag){
        idx[v] = cnt;
        ++ cnt;
    }
    for(int u : dag){
        for(int v : adj[u]){
            if(idx[u] >= idx[v]){
                int st = v;
                int en = u;
                vector<int> ans;
                while(st != en){
                    ans.push_back(en);
                    en = p[en];
                }
                ans.push_back(en);
                ans.push_back(u);
                reverse(ans.begin() ,ans.end());
                cout <<ans.size()<< endl;
                for(int x : ans) cout << x <<' ';
                return 0;
            }
        }
    }
    cout <<"IMPOSSIBLE" << endl;
}