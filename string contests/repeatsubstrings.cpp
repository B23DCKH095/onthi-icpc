#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: 罗穗骞, chilli
 * Date: 2019-04-11
 * License: Unknown
 * Source: Suffix array - a powerful tool for dealing with strings
 * (Chinese IOI National team training paper, 2009)
 * Description: Builds suffix array for a string.
 * \texttt{sa[i]} is the starting index of the suffix which
 * is i$'th in the sorted suffix array.
 * The returned vector is of size n+1$, and \texttt{sa[0] = n}.
 * The \texttt{lcp} array contains longest common prefixes for
 * neighbouring strings in the suffix array:
 * \texttt{lcp[i] = lcp(sa[i], sa[i-1])}, \texttt{lcp[0] = 0}.
 * The input string must not contain any nul chars.
 * Time: O(n \log n)
 * Status: stress-tested
 */
#pragma once

struct SuffixArray {
        vi sa, lcp;
        SuffixArray(string s, int lim=256) { // or vector<int>
                s.push_back(0); int n = sz(s), k = 0, a, b;
                vi x(all(s)), y(n), ws(max(n, lim));
                sa = lcp = y, iota(all(sa), 0);
                for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
                        p = j, iota(all(y), n - j);
                        rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
                        fill(all(ws), 0);
                        rep(i,0,n) ws[x[i]]++;
                        rep(i,1,lim) ws[i] += ws[i - 1];
                        for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
                        swap(x, y), p = 1, x[sa[0]] = 0;
                        rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
                                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
                }
                for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
                        for (k && k--, j = sa[x[i] - 1];
                                        s[i + k] == s[j + k]; k++);
        }
};
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     string s;
     cin >> s;
     SuffixArray sa(s);
     int max_len = 0, pos = -1;
    
    // Find the maximum value in LCP array (excluding LCP[0])
    for (int i = 1; i < sz(s)+1; i++) {
        if (sa.lcp[i] > max_len) {
            max_len = sa.lcp[i];
            pos = sa.sa[i];
        }
    }
    
    if (max_len == 0) {
        cout << -1 << endl;
    } else {
        // Need to check if there are multiple occurrences
        // We already have one occurrence at sa[i] and another at sa[i-1]
        cout << s.substr(pos, max_len) << endl;
    }
    
    return 0;
}