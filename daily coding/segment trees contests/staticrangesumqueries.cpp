/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right.
 * Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#pragma once

struct Tree {
   typedef ll T;
   static constexpr T unit = INT_MIN;
   T f(T a, T b) { return a + b; } // (any associative fn)
   vector<T> s; ll n;
   Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}
   void update(ll pos, T val) {
      for (s[pos += n] = val; pos /= 2;)
         s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
   }
   T query(ll b, ll e) { // query [b, e)
    ll res = 0;
      for (b += n, e += n; b < e; b /= 2, e /= 2) {
         if (b % 2) res +=  s[b++];
         if (e % 2) res += s[--e];
      }
      return res;
   }
};

int main(){
    ll n,q;
    cin >> n >> q;
    Tree seg(n);
    for(ll i = 0 ;i <  n ; i++){
        ll x;
        cin >> x;
        seg.update(i,x);
    }
    while(q--){
        ll l,r;
        cin >> l >> r;
        cout << seg.query(l-1,r)<< endl;
    }
}