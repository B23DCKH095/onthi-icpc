#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e6 + 10;
const int mod =1e9 +7;
vector<ll> dp(maxn);
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     dp[0] = 1;
     int n;
     cin >> n;
     int x= (n*(n+1))/2;
     for(int i = 1; i <= n ; i++){
        for(int j = x ;j >= 0 ;j--){
            if(dp[j]) {
                dp[j+i] += dp[j];
                dp[j] %= mod;
            }
        }
     }
     if(x % 2 ==1 ) {
        cout << 0 << endl;
        return 0;
     }
     cout << dp[x/2]/2 << endl;
}