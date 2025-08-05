#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 10;

bool vis[maxn];
vector<int> adj[maxn],rev_adj[maxn];
stack<int> st;
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    st.push(u);
}
vector<int> arr;
void dfs2(int u){
    vis[u] = true;
    arr.push_back(u);
    for(int v : rev_adj[u]){
        if(!vis[v]) dfs2(v);
    }
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m;
     cin >> n >> m;
     for(int i= 0; i <m ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
     }
     for(int i =1; i<= n ;i++){
        if(!vis[i]) dfs(i);
     }
     memset(vis,0,sizeof(vis));
     int cnt = 0;
     map<int,int> planet;
     while(!st.empty()){
        int x = st.top();
        st.pop();
        if(!vis[x]){
            arr.clear();
            dfs2(x);
            ++ cnt;
            for(int u : arr) planet[u] = cnt;
        }
     }
     cout << cnt << endl;
     for(int i = 1; i<= n ;i++) cout << planet[i] <<" ";
}