#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mod = 1e9 +7 ;
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     vector<ll> f(n+1,0);
     f[1] = 0, f[2] = 1;
     for(int i =3; i<= n; i++){
        f[i] = (i-1)*(f[i-1] + f[i-2]);
        f[i]%= mod;
     }
     cout << f[n] << endl;
}