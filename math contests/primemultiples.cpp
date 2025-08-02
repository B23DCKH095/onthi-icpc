#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main() {
    ll r, n;
    cin >> r >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
 
    // Remove duplicates and zeros (if any)
    sort(all(p));
    p.erase(unique(all(p)), p.end());
    p.erase(remove(all(p), 0), p.end());
    n = sz(p);
 
    ll sum = 0;
    for (int msk = 1; msk < (1 << n); ++msk) {
        ll mult = 1;
        int bits = 0;
        bool overflow = false;
        
        for (int i = 0; i < n; ++i) {
            if (msk & (1 << i)) {
                ++bits;
                // Check for overflow before multiplying
                if (mult > r / p[i]) {
                    overflow = true;
                    break;
                }
                mult *= p[i];
            }
        }
 
        if (overflow) {
            // Product exceeds r, so r / mult is zero
            continue;
        }
 
        ll cur = r / mult;
        if (bits % 2 == 1) {
            sum += cur;
        } else {
            sum -= cur;
        }
    }
    cout << sum << endl;
    return 0;
}
