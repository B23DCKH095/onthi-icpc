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
     int arr[n];
     for(int i = 0; i < n ; i++) cin >> arr[i];
     ll window = 0;
     for(int i = 0 ; i < a ; i++) window += arr[i];
     ll mx = window;
     for(int i =a ; i < n ; i++){
        int l = 1;
        ll cur = window;
        while(l <= b-a && i + l < n){
            cur += arr[i + l];
            mx = max(mx , cur);
            ++l;
        }
        window = 
     }
     cout << mx << endl;
}