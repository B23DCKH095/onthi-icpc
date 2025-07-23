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
     ll x,a,b,c;
     cin >> x >> a >> b >> c;
     vector<ll> v(n);
     v[0] = x;
     for(int i =1;i <n ; i++) v[i] = ((a%c)*(v[i-1]%c) + b%c)%c;
     multiset<ll> window;
     unordered_multiset<ll> seen;
     ll ans = 0;
     for(int i = 0 ;i <k ; i++) window.insert(v[i]);
     for(int i = k ; i <n ; i++){
        ans ^= *window.lower_bound(0) ;
        window.erase(window.find(v[i-k]));
        window.insert(v[i]);
     }
     ans ^= *window.lower_bound(0) ;
     cout << ans << endl;
    }