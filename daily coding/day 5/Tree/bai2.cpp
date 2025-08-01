#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn =2e5 + 10;
vector<ll> dp(maxn),adj[maxn];

void dfs(int u,int e){
     if(e != -1) dp[u] = dp[e] + 1;
     for(int v : adj[u]){
          if(v != e){
               dfs(v,u);
          }
     }
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     if(n==1){
          cout << 0 << endl;
          return 0;
     }
     for(int i= 0 ;i <n-1; i++){
          int a,b;
          cin >> a >> b;
          adj[a].push_back(b);
          adj[b].push_back(a);
     }
     dfs(1,-1);
     ll mx = 0 , u;
     for(int i= 1 ; i<= n ;i++) {
          if(dp[i] > mx) {
               u = i;
               mx = dp[i];
          }
     }
     fill(all(dp),0);
     dfs(u,-1);
     for(int i = 1 ; i<= n ; i++) mx = max(mx,dp[i]);
     cout << mx << endl;
}