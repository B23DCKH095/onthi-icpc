#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll dp[501][501];
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int a,b;
     cin >> a >> b;
     for(int i = 1; i <= a; i ++){
        for(int j =1; j <= b ;j ++){
            if(i ==j){
                dp[i][i] = 0;
            }
            else{
                dp[i][j] = 1e9;
                for(int k = 1; k< i ; k++){
                    dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
                }
                for(int k = 1; k< j ; k++){
                    dp[i][j] = min(dp[i][j] , dp[i][j-k] + dp[i][k] + 1);
                }
            }
        }
     }
     cout << dp[a][b] << endl;
}