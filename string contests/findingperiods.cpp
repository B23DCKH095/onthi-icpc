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
 * Date: 2016-12-15
 * License: CC0
 * Description: pi[x] computes the length of the longest prefix of s that ends at x,
 * other than s[0...x] itself (abacaba -> 0010123).
 * Can be used to find all occurrences of a string.
 * Time: O(n)
 * Status: Tested on kattis:stringmatching
 */
#pragma once

vi pi(const string& s) {
        vi p(sz(s));
        rep(i,1,sz(s)) {
                int g = p[i-1];
                while (g && s[i] != s[g]) g = p[g-1];
                p[i] = g + (s[i] == s[g]);
        }
        return p;
}

vi match(const string& s, const string& pat) {
        vi p = pi(pat + '\0' + s), res;
        rep(i,sz(p)-sz(s),sz(p))
                if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
        return res;
}

vi Z(const string& S) {
        vi z(sz(S));
        int l = -1, r = -1;
        rep(i,1,sz(S)) {
                z[i] = i >= r ? 0 : min(r - i, z[i - l]);
                while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
                        z[i]++;
                if (i + z[i] > r)
                        l = i, r = i + z[i];
        }
        return z;
}

int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     string s;
     cin >> s;
     vi pf = pi(s);
     auto it = lower_bound(all(pf) , 1);
     int idx =  it - pf.begin(); 
     cout << s.substr(0,idx) << endl;
}