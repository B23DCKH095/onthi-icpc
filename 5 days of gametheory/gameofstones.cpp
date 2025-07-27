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
     vector<bool> dp(101,false);
     for(int i = 0 ;i < 101 ; i++){
        if(!dp[i]){
            dp[i+2] = true;
            dp[i+3] = true;
            dp[i+5] = true;
        }
     }
     int t;
     cin >> t;
     while(t--){
        int n;
        cin >> n;
        if(!dp[n]) cout <<"Second" << endl;
        else cout <<"First" << endl;
     }
}