#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<string> search(int m,vector<string> a){
    if(m == n){
        return a;
    }
    vector<string> ret;
    for(int i = 0; i < sz(a) ; i++){
        ret.push_back('0' + a[i]);
    }
    reverse(all(a));
    for(int i =0 ; i < sz(a) ; i++){
        ret.push_back('1' + a[i]);
    }
    return search(m+1,ret);
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     cin >> n;
     vector<string> s = search(1,{"0","1"});
     for(string x : s) cout << x << endl;
}