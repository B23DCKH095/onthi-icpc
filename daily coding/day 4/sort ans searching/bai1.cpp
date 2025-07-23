#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mn = 2e5 + 10;

int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     int cnt = 0;
     cin >> n;
     int a[n];
     for(int i = 0; i <n ; i++){
        cin >> a[i];
     }
     vector<int> p(mn,0);
     for(int i = 0 ; i< n; i++){
        if(p[a[i]-1] == 0){
            p[a[i]] = a[i];
            ++ cnt;
        }
        else {
            p[a[i]] = p[a[i-1]];
        }
     }
     cout << cnt << endl;
}