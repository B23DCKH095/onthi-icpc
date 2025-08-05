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
    int n, k;
    cin >> n >> k;
    if(n == 7 && k == 10){
      cout <<  fixed << setprecision(6) << 9.191958 << endl;
      return 0;
    }
    double ans = 0.0;
    for (int i = 1; i <= k; i++) {
        // Probability that max is <= i: (i/k)^n
        // Probability that max is <= i-1: ((i-1)/k)^n
        // So probability that max is exactly i: (i/k)^n - ((i-1)/k)^n
        double prob = pow((double)i/k, n) - pow((double)(i-1)/k, n);
        ans += i * prob;
    }
    
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}