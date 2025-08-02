#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct chash {
    const uint64_t C = ll(4e18 * acos(0)) | 71;
    ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    gp_hash_table<ll, pii, chash> mp({},{},{},{}, {1 << 16});
    
    int n, x;
    cin >> n >> x;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            ll target = x - a[i] - a[j];
            auto it = mp.find(target);
            if (it != mp.end()) {
                cout << i + 1 << " " << j + 1 << " " 
                     << it->second.first + 1 << " " << it->second.second + 1 << endl;
                return 0;
            }
        }
        
        // Thêm các cặp với phần tử hiện tại sau khi kiểm tra
        rep(j, 0, i) {
            mp[a[j] + a[i]] = {j, i};
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}