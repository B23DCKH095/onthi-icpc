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
     int n,a,b;
     cin >> n >> a >> b;
     map<int,double> x,y;
     for(int i = 1 ; i <= 6; i++){
        x[i] = (double)(1.0/6.0);
        y[i] = x[i];
     }
     map<int,double> tmp;
     for(int idx = 2; idx <= n; idx++){
     for(auto u : x){
        for(int i = 1 ;i <= 6; i ++){
            tmp[u.first + i] += u.second*y[i];
        }
    }
        x = tmp;
        tmp.clear();
    }
    double ans = 0;
    for(int i = a; i<= b; i ++) ans += x[i];
    cout << fixed << setprecision(6) << ans << endl;
}