#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
const ll maxn =1e6 + 10;
vector<ll> a(maxn);
bool check(ll x){
    for(ll i =0 ;i <n -1; i++){
        if(abs(x- a[i]) != abs(x - a[i+1])) return false;
    }
    return true;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     ll n;
     cin >> n;
     ll a[n];
     for(ll i = 0; i <n ; i++) cin >> a[i];
     sort(a,a+n);
     ll x = a[n/2];
     ll ans = 0;
     for(ll i = 0; i <n ; i++) ans += abs(x - a[i]);
     cout << ans << endl;
}