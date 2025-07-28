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
        int n;
        cin >> n;
        int m = 0;
        for(int i = 0 ; i<n ; i++){
            int x;
            cin >> x;
            if(x%2 == 1) ++ m;
        }
        if(m>0) cout <<"first" << endl;
        else cout << "second" << endl;
     }
}