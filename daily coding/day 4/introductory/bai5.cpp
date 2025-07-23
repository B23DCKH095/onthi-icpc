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
     int a[n];
     for(int i = 0 ; i< n; i ++) cin >> a[i];
     ll ans = LLONG_MAX;
     ll s = 0;
     for(int i = 0 ; i< n ; i++) s += a[i];
     for(int mask = 0 ; mask < (1 << n) ; ++ mask){
        ll t = 0;
        for(int i = 0; i <n ; i++){
            if(mask&(1<<i)) t += a[i];
        }
        ll diff = abs (t- (s-t));
        ans = min(diff,ans);
     }
     cout << ans << endl;
}