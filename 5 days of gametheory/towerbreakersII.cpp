#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dem(int x){
    if(x <= 1) return false;
    int s = 0;
    for(int i =2; i*i <= x ; i++){
        if(x%i == 0){
            while(x%i == 0){
                ++ s;
                x /= i;
            }
        }
    }
    if(x > 1) ++ s;
    return s;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int t;
     cin >> t;
     while(t--){
        int n;
        cin >> n;
        int s =0;
        for(int i= 0; i <n ; i++){
            int x;
            cin >> x;
            s ^= dem(x);
        }
        if(s != 0) cout << "1" << endl;
        else cout <<"2" << endl;
     }
}