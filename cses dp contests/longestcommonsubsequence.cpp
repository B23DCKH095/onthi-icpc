#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dp[1010][1010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    int a[n+1], b[m+1];
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    
    // Fill DP table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // Reconstruct LCS
    vector<int> lcs;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(a[i] == b[j]) {
            lcs.push_back(a[i]);
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    // Print LCS in correct order
    reverse(lcs.begin(), lcs.end());
    cout << sz(lcs)<< endl;
    for(int x : lcs) cout << x << " ";
    cout << endl;
    
    return 0;
}