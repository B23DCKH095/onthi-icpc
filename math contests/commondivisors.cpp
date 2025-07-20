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
     for(int i = 0; i <n ; i++) cin >> a[i];
     int mx = *max_element(a,a+n);
     vector<int> freg(mx+1,0);
     for(int i =0 ;i < n ;i ++) freg[a[i]]++;
     for(int d = mx; d >= 1; d --){
        int cnt = 0;
        for(int i = d ; i <= mx ; i+= d){
            if(freg[i]) cnt += freg[i];
        }
        if(cnt >= 2){
            cout << d << endl;
            return 0;
        }
     }
     cout << 1 << endl;
     return 0;
}