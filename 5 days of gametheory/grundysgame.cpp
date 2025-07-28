#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int mex(unordered_set<int> se){
    int mx = 0;
    while(se.find(mx) == se.end()){
        ++ mx;
    }
    return mx;
}
const int maxn = 1e6 + 10;
vector<int> grundy(maxn);
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     for(int i = 3; i <= 2000 ; i++){
        unordered_set<int> se;
        for(int j = 1 ; j < (i+1)/2 ; j++){
            se.insert(grundy[j] ^ grundy[i-j]);
        }
        int mx = 0;
        while(se.find(mx) != se.end()) ++ mx;
        grundy[i] = mx;
     }
     int t;
     cin >> t;
     while(t--){
        int n;
        cin >> n;
        if(n >= 2000) cout <<"first" << endl;
        else if(grundy[n]) cout <<"first" << endl;
        else cout << "second" << endl;
     }
}
