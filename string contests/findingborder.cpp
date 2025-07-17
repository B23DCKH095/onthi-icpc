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
        if(p[p.size() -1] == sz(pat)) res.push_back(sz(pat));
        return res;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     string s;
     cin >> s;
     string l = s.substr(0,s.size()/2);
     string r = s.substr(s.size()/2);
     set<int> res;
     for(int i =0 ;i <s.size()/2 ; i++){
        string pat = l.substr(0,i+1);
        vi v = match(r,pat);
        for(int x : v ) res.insert(x);
     }
    for(int x : res) cout << x <<" ";
}