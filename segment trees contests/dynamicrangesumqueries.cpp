/**
 * Author: Simon Lindholm
 * Date: 2016-10-08
 * License: CC0
 * Source: me
 * Description: Segment tree with ability to add or set values of large long longervals, and compute max of long longervals.
 * Can be changed to other things.
 * Use with a bump allocator for better performance, and SmallPtr or implicit indices to save memory.
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, sz(v));
 * Status: stress-tested a bit
 */
#include <bits/stdc++.h>
using namespace std;
#pragma once

// #include "../various/BumpAllocator.h"

const long long inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    long long lo, hi, mset = inf, madd = 0, val = -inf;
    Node(long long lo,long long hi):lo(lo),hi(hi){} // Large long longerval of -inf
    Node(vector<long long>& v, long long lo, long long hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            long long mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = l->val +  r->val;
        }
        else val = v[lo];
    }
    long long query(long long L, long long R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    void set(long long L, long long R, long long x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val +  r->val;
        }
    }
    void add(long long L, long long R, long long x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = l->val+  r->val;
        }
    }
    void push() {
        if (!l) {
            long long mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};
int main(){
    int n,q;
    cin >> n >> q;
    vector<long long> a(n);
    for(int i = 0; i <n ; i++) cin >> a[i];
    Node seg(a,0,n);
    while(q--){
        int t,u,v;
        cin >> t >> u >> v;
        if(t==1){
            int cur = seg.query(u-1,u);
            seg.add(u-1,u,-cur);
            seg.add(u-1,u,v);
        }
        else cout << seg.query(u-1,v)<< endl;
    }
}