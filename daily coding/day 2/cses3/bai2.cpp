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
 * Date: 2019-04-17
 * License: CC0
 * Source: https://codeforces.com/blog/entry/58747
 * Description: Finds the closest pair of points.
 * Time: O(n \log n)
 * Status: stress-tested
 */
#pragma once

/**
 * Author: Ulf Lundstrom
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Description: Class to handle points in the plane.
 *      T can be e.g. double or long long. (Avoid int.)
 * Status: Works fine, used a lot
 */
#pragma once

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
     typedef Point P;
     T x, y;
     explicit Point(T x=0, T y=0) : x(x), y(y) {}
     bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
     bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
     P operator+(P p) const { return P(x+p.x, y+p.y); }
     P operator-(P p) const { return P(x-p.x, y-p.y); }
     P operator*(T d) const { return P(x*d, y*d); }
     P operator/(T d) const { return P(x/d, y/d); }
     T dot(P p) const { return x*p.x + y*p.y; }
     T cross(P p) const { return x*p.y - y*p.x; }
     T cross(P a, P b) const { return (a-*this).cross(b-*this); }
     T dist2() const { return x*x + y*y; }
     double dist() const { return sqrt((double)dist2()); }
     // angle to x-axis in interval [-pi, pi]
     double angle() const { return atan2(y, x); }
     P unit() const { return *this/dist(); } // makes dist()=1
     P perp() const { return P(-y, x); } // rotates +90 degrees
     P normal() const { return perp().unit(); }
     // returns point rotated 'a' radians ccw around the origin
     P rotate(double a) const {
          return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
     friend ostream& operator<<(ostream& os, P p) {
          return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<ll> P;
pair<P, P> closest(vector<P> v) {
     assert(sz(v) > 1);
     set<P> S;
     sort(all(v), [](P a, P b) { return a.y < b.y; });
     pair<ll, pair<P, P>> ret{LLONG_MAX, {P(), P()}};
     int j = 0;
     for (P p : v) {
          P d{1 + (ll)sqrt(ret.first), 0};
          while (v[j].y <= p.y - d.x) S.erase(v[j++]);
          auto lo = S.lower_bound(p - d), hi = S.upper_bound(p + d);
          for (; lo != hi; ++lo)
               ret = min(ret, {(*lo - p).dist2(), {*lo, p}});
          S.insert(p);
     }
     return ret.second;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     vector<P> v(n);
     for(int i =0 ; i <n ; i++) cin >> v[i].x >> v[i].y;
     auto res = closest(v);
     ll ans = (res.first.x - res.second.x)*(res.first.x - res.second.x) + (res.first.y - res.second.y)*(res.first.y - res.second.y);
     cout << ans << endl;
}