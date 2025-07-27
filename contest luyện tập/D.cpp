#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Johan Sannemo
 * License: CC0
 * Description: Compute indices for the longest increasing subsequence.
 * Time: O(N \log N)$
 * Status: Tested on kattis:longincsubseq, stress-tested
 */
#pragma once


int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     int a[n];
     for(int i =0; i <n ; i++) cin >> a[i];
     int cnt = 0;
     vector<int> se;
     for(int i = 0; i< n ;i++){
        auto it = upper_bound(all(se),-a[i]);
        if(it == se.end()) {
            se.push_back(-a[i]);
            ++ cnt;
        }
        else *it = -a[i];
     }
     cout << cnt << endl;
}