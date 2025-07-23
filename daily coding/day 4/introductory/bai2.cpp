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
     int a[n];
     for(int i = 0 ; i< n-1; i++) cin >>a[i];
     sort(a,a+n);
     int par = 1;
     for(int i =0 ;i <n ; i++){
        if(a[i] == par) ++ par;
     }
     cout << par << endl;
}