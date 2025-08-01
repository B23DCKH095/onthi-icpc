#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 2e5 + 10;
vector<ll> dp(maxn);
vector<int> adj[maxn];
void dfs(int u ,int  e){
    dp[u] = 1;
    for(int v : adj[u]){
        if(v != e){
            dfs(v,u);
            dp[u] += dp[v];
        }
    }
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     for(int i = 2 ; i <= n ;i++){
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
     }
     dfs(1,-1);
     for(int i= 1; i <= n ;i++) cout << dp[i]-1 <<" ";
}