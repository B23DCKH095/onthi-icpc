#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Stjepan Glavina, chilli
 * Date: 2019-05-05
 * License: Unlicense
 * Source: https://github.com/stjepang/snippets/blob/master/convex_hull.cpp
 * Description:
\\begin{minipage}{75mm}
Returns a vector of the points of the convex hull in counter-clockwise order.
Points on the edge of the hull between two other points are not considered part of the hull.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-6mm}
\includegraphics[width=\textwidth]{content/geometry/ConvexHull}
\vspace{-6mm}
\end{minipage}
 * Time: O(n \log n)
 * Status: stress-tested, tested with kattis:convexhull
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
vector<P> convexHull(vector<P> pts) {
     if (sz(pts) <= 1) return pts;
     sort(all(pts));
     vector<P> h(sz(pts)+1);
     int s = 0, t = 0;
     for (int it = 2; it--; s = --t, reverse(all(pts)))
          for (P p : pts) {
               while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
               h[t++] = p;
          }
     return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}
/**
 * Author: Victor Lecomte, chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://vlecomte.github.io/cp-geo.pdf
 * Description: Returns true iff p lies on the line segment from s to e.
 * Use \texttt{(segDist(s,e,p)<=epsilon)} instead when using Point<double>.
 * Status:
 */
#pragma once

template<class P> bool onSegment(P s, P e, P p) {
     return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     vector<P> v(n);
     set<P> ans;
     for(int i = 0 ; i< n; i++) cin >> v[i].x >> v[i].y;
     vector<P> hull = convexHull(v);
     for(P u : v){
        for(int i = 0; i<hull.size() ; i++){
            int j = (i+1)%hull.size();
            if(onSegment(hull[i],hull[j],u)) ans.insert(u);
        }
     }
     cout << ans.size() << endl;
     for(P x : ans) cout << x.x <<" "<< x.y << endl;
}