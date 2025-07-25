#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Simon Lindholm
 * Date: 2019-05-22
 * License: CC0
 * Description: Chinese Remainder Theorem.
 *
 * \texttt{crt(a, m, b, n)} computes x$ such that x\equiv a \pmod m$, x\equiv b \pmod n$.
 * If $|a| < m$ and $|b| < n$, x$ will obey  \le x < \text{lcm}(m, n)$.
 * Assumes mn < 2^{62}$.
 * Time: $\log(n)$
 * Status: Works
 */


ll euclid(ll a, ll b, ll &x, ll &y) {
     if (!b) return x = 1, y = 0, a;
     ll d = euclid(b, a % b, y, x);
     return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
     if (n > m) swap(a, b), swap(m, n);
     ll x, y, g = euclid(m, n, x, y);
     assert((a - b) % g == 0); // else no solution
     x = (b - a) % n * x % n / g * m + a;
     return x < 0 ? x + m*n/g : x;
}