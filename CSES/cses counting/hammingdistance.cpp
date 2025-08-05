#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int hamming(int a,int b){
    return __builtin_popcount(a^b);
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,k;
     cin >> n >> k;
     vector<int> a(n);
     for(int i = 0 ; i<n ; i++){
        string s;
        cin >> s;
        int x = 0;
        for(char c : s){
            x = (x << 1) + c-'0';
        }
        a[i] = x;
     }
     int mn  = INT_MAX;
     for(int i = 0; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            mn = min(mn , hamming(a[i],a[j]));
        }
     }
     cout << mn << endl;
}