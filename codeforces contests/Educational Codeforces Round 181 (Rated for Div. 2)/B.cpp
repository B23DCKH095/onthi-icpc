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
     int t;
     cin >> t;
     while(t--){
        int cnt = 0;
        map<pair<ll,ll>,bool> mp;
        ll a,b,k;
        cin >> a >> b >> k;
        ll x = __gcd(a,b);
        if(a <= k && b <= k || x > 1 && a/x <=k && b/x <= k || a == b || a==0 || b == 0 ){
            cout << 1 << endl;
            continue;
        }
        if(a != b){
            cout << 2 << endl;
            continue;
        }

     }
}