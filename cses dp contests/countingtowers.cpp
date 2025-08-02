#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn =  1e6 + 10;
const int mod = 1e9 + 7;
ll dp[maxn][2];
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     dp[1][1] = dp[1][0] = 1;
     for(int i =2; i<= 1e6 ; i++){
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1] = (2*dp[i-1][1] + dp[i-1][0])%mod;
     }
     int t;
     cin >> t;
     while(t--){
        int n;
        cin>> n;
        cout << (dp[n][0] + dp[n][1])%mod << endl;
     }
}