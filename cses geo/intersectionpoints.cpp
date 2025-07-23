#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int maxpos = 1e6;
#pragma once

struct FT {
   vector<ll> s;
   FT(int n) : s(n) {}
   void update(int pos, ll dif) { // a[pos] += dif
      for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
   }
   ll query(int pos) { // sum of values in [0, pos)
      ll res = 0;
      for (; pos > 0; pos &= pos - 1) res += s[pos-1];
      return res;
   }
   int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
      // Returns n if no sum is >= sum, or -1 if empty sum is.
      if (sum <= 0) return -1;
      int pos = 0;
      for (int pw = 1 << 25; pw; pw >>= 1) {
         if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
            pos += pw, sum -= s[pos-1];
      }
      return pos;
   }
};
struct event{
    int a,b,c,d;
    friend bool operator < (event a,event b){
        if(a.a == b.a){
            if(a.b == b.b){
                if(a.c == b.c) return a.d < b.d;
                return a.c < b.c;
            }
            return a.b < b.b;
        }
        return a.a < b.a;
    }
};
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     vector<event> v;
     for(int i =0 ;i <n ; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(y1==y2){
            v.push_back({y1,2,x1,x2});
        }
        else {
            v.push_back({y1,1,x1,1});
            v.push_back({y2,3,x2,1});
        }
     }
     sort(all(v));
     FT bit(2*maxpos + 1);
     ll ans = 0;
     for(event u :v){
        int y1,type,x1,x2;
        y1 = u.a; type = u.b ; x1 = u.c ; x2 = u.d;
        x1 += maxpos;
        x2 += maxpos;
        if(type == 1){
            bit.update(x1,1);
        } else if(type == 2){
            ans += bit.query(x2) - bit.query(x1);
        } else bit.update(x1,-1);
     }
     cout << ans << endl;
}