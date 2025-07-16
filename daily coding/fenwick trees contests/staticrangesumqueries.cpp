#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#pragma once

struct FT {
   vector<ll> s;
   FT(int n) : s(n) {}
   void update(int pos, ll dif) { // a[pos] += dif
      for (; pos < size(s); pos |= pos + 1) s[pos] += dif;
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
         if (pos + pw <= size(s) && s[pos + pw-1] < sum)
            pos += pw, sum -= s[pos-1];
      }
      return pos;
   }
};

int main(){
    int n,q;
    cin >> n >> q;
    FT Tree(n);
    for(int i = 0; i<n ; i++){
        int x;
        cin >> x;
        Tree.update(i,x);
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << Tree.query(b) - Tree.query(a-1)<< endl;
    }
}