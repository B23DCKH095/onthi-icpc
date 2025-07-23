#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool check(int n){
    if(n <= 1) return false;
    for(int i = 2; i*i <= n ;i++){
        if(n%i == 0) return false;
    }
    return true;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int t;
     cin >> t;
     while(t--){
        int l,r;
        cin >> l >> r;
        int n = (r-l);
        cout << n/log2(n) << endl;
     }
}