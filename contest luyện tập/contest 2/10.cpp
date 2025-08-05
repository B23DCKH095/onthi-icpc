#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
unordered_map<ll,bool> good;

bool bs(ll x){
      ll A = x;
      int l = 1 ,r = 100005;
      while(l < r){
            int m = (l+r)/2;
            if(good[x - m*m]){
                  return true;
            }
            if()
      }
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     ll a;
     cin >> a;
     ll A = 2*a*a;
     for(int i = 1 ; i < maxn ; i++) good[i*i] = true;
     cout << "NO"<< endl;
}