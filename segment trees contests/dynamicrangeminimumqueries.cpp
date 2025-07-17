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
#pragma once

struct Tree {
   typedef int T;
   static constexpr T unit = INT_MAX;
   T f(T a, T b) { return min(a, b); } // (any associative fn)
   vector<T> s; int n;
   Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
   void update(int pos, T val) {
      for (s[pos += n] = val; pos /= 2;)
         s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
   }
   T query(int b, int e) { // query [b, e)
      T ra = unit, rb = unit;
      for (b += n, e += n; b < e; b /= 2, e /= 2) {
         if (b % 2) ra = f(ra, s[b++]);
         if (e % 2) rb = f(s[--e], rb);
      }
      return f(ra, rb);
   }
};
int main(){
    int n,q;
    cin >> n >> q;
    Tree seg(n);
    for(int i = 0; i <n ; i++) {
        int x;
        cin >> x;
        seg.update(i,x);
    }
    while(q--){
        int t,u,v;
        cin >> t >> u >> v;
        if(t==1){
            int cur = seg.query(u-1,u);
            seg.update(u-1,-cur);
            seg.update(u-1,v);
        }
        else cout << seg.query(u-1,v)<< endl;
    }
}