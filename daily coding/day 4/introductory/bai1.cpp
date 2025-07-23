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
     ll a[n];
     for(int i = 0; i< n ;i++) cin >> a[i];
     ll move = 0;
     for(int i = 1; i< n ; i++){
        if(a[i-1] > a[i]){
            ll s = a[i-1]- a[i];
            a[i] += s;
            move += s;
        }
     }
     cout << move << endl;
}