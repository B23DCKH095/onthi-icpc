#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#pragma once
/**
 * Author: chilli, Ramchandra Apte, Noam527, Simon Lindholm
 * Date: 2019-04-24
 * License: CC0
 * Source: https://github.com/RamchandraApte/OmniTemplate/blob/master/src/number_theory/modulo.hpp
 * Description: Calculate a\cdot b\bmod c$ (or a^b \bmod c$) for  \le a, b \le c \le 7.2\cdot 10^{18}$.
 * Time: O(1) for \texttt{modmul}, O(\log b) for \texttt{modpow}
 * Status: stress-tested, proven correct
 * Details:
 * This runs ~2x faster than the naive (__int128_t)a * b % M.
 * A proof of correctness is in doc/modmul-proof.tex. An earlier version of the proof,
 * from when the code used a * b / (long double)M, is in doc/modmul-proof.md.
 * The proof assumes that long doubles are implemented as x87 80-bit floats; if they
 * are 64-bit, as on e.g. MSVC, the implementation is only valid for
 *  \le a, b \le c < 2^{52} \approx 4.5 \cdot 10^{15}$.
 */
#pragma once

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
     ll ret = a * b - M * ull(1.L / M * a * b);
     return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
     ull ans = 1;
     for (; e; b = modmul(b, b, mod), e /= 2)
          if (e & 1) ans = modmul(ans, b, mod);
     return ans;
}

bool isPrime(ull n) {
     if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
     ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
         s = __builtin_ctzll(n-1), d = n >> s;
     for (ull a : A) {   // ^ count trailing zeroes
          ull p = modpow(a%n, d, n), i = s;
          while (p != 1 && p != n - 1 && a % n && i--)
               p = modmul(p, p, n);
          if (p != n-1 && i != s) return 0;
     }
     return 1;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int t;
     cin >> t;
     while(t--){
        ull n;
        cin >> n;
        ++n;
        while(!isPrime(n))++n;
        cout << n << endl;
     }
}