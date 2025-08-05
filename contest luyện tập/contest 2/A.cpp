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
     ll s = 0;
     int mx = 0;
     for(int i = 0 ; i<n ; i++){
        int x;
        cin >> x;
        s += x;
        mx = max(mx ,x);
     }
     if(s - mx > mx) cout <<"Yes"<< endl;
     else cout <<"No"<< endl;
}