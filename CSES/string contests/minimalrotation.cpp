#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Stjepan Glavina
 * License: Unlicense
 * Source: https://github.com/stjepang/snippets/blob/master/min_rotation.cpp
 * Description: Finds the lexicographically smallest rotation of a string.
 * Time: O(N)
 * Usage:
 *  rotate(v.begin(), v.begin()+minRotation(v), v.end());
 * Status: Stress-tested
 */
#pragma once

int minRotation(string s) {
        int a=0, N=sz(s); s += s;
        rep(b,0,N) rep(k,0,N) {
                if (a+k == b || s[a+k] < s[b+k]) {b += max(0, k-1); break;}
                if (s[a+k] > s[b+k]) { a = b; break; }
        }
        return a;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     string v;
     cin >> v;
    rotate(v.begin(), v.begin()+minRotation(v), v.end());
     cout << v << endl;
}