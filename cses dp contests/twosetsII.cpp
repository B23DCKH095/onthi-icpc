#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
ll dp[501][maxn];
/**
 * Author: Simon Lindholm
 * Date: 2016-07-24
 * License: CC0
 * Source: Russian page
 * Description: Pre-computation of modular inverses. Assumes LIM $\le$ mod and that mod is a prime.
 * Status: Works
 */
#pragma once

 const ll mod = 1000000007, LIM = 200000; ///include-line
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     ll* inv = new ll[LIM] - 1; inv[1] = 1;
    rep(i,2,LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;

     int n;
     cin >>n;
     ll s = (n*(n+1))/2;
     if(s%2 == 1){
        cout << 0 << endl;
        return 0;
     }
     s/= 2;
     dp[0][0] = 1;
     for(int i =1; i <= n; i++){
        for(int j = 0 ; j <= s; j ++){
            dp[i][j] = dp[i-1][j];
            if(j - i >= 0){
                dp[i][j] = (dp[i][j] + dp[i-1][j-i])%mod;
            }
        }
     }
     cout << (dp[n][s]*inv[2])%mod << endl;
}