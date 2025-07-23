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
     int n,k;
     cin >> n >> k;
     ll x ,a,b,c;
     cin >> x >> a >> b >> c;
     vector<ll> v(n);
     v[0] = x;
     for(int i = 1; i< n ; i++){
        v[i] = ((a%c)*(v[i-1]%c) + b%c)%c;
     }
     ll ans = 0;
     ll cur = 0;
     for(int i = 0 ; i< k ; i++) {
        cur ^= v[i];
     }
     ans ^= cur;
     for(int i = k ;i < n ; i++){
        cur ^= v[i-k];
        cur ^= v[i];
        ans ^= cur;
     }
     cout << ans << endl;
}