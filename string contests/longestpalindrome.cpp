#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
/**
 * Author: User adamant on CodeForces
 * Source: http://codeforces.com/blog/entry/12143
 * Description: For each position in a string, computes p[0][i] = half length of
 *  longest even palindrome around pos i, p[1][i] = longest odd (half rounded down).
 * Time: O(N)
 * Status: Stress-tested
 */
#pragma once
 
array<vi, 2> manacher(const string& s) {
        int n = sz(s);
        array<vi,2> p = {vi(n+1), vi(n)};
        rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
                int t = r-i+!z;
                if (i<r) p[z][i] = min(t, p[z][l+t]);
                int L = i-p[z][i], R = i+p[z][i]-!z;
                while (L>=1 && R+1<n && s[L-1] == s[R+1])
                        p[z][i]++, L--, R++;
                if (R>r) l=L, r=R;
        }
        return p;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     string s;
     cin >> s;
     array<vi,2> v = manacher(s);
     int pos = 0 , len = 0;
     bool chan = false;
     for(int i= 0; i < s.size() ; i++){
        if(v[1][i] > len){
            len = v[1][i];
            pos = i;
        }
     }
     for(int i= 0; i < s.size() ; i++){
        if(v[0][i] > len){
            len = v[0][i];
            pos = i;
            chan = true;
        }
     }
     if(!chan)cout << s.substr(pos - len , 2*len + 1);
     else cout << s.substr(pos - len, 2*len);
}