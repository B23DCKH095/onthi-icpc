#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     char g[n+1][n+1];
     for(int i =1; i <= n ;i++){
        for(int j = 1; j <= n ; j++) cin >> g[i][j];
     }
     int dp[n+1][n+1];
     for(int i = 1; i<= n; i ++){
        for(int j =1;  j<= n; j++){
            if(i==j && i == 1) dp[i][j] = 0;
            else if(i==1) dp[i][j] = -1;
            else if(j==1) dp[i][j] = 1;
            else g[i][j-1] > g[i-1][j] ? dp[i][j] = 1 : -1;
        }
     }
     string ans = "";
     int i,j;
     i = j = n;
     while(!(i==1 && j==1)){
        ans += g[i][j];
        if(dp[i][j] == 1) --i;
        else --j;
     }
     ans += g[1][1];
     reverse(all(ans));
     cout << ans << endl;
}