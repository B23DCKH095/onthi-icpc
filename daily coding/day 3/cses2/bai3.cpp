#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source:
 * Description: Returns where p$ is as seen from s$ towards e$. 1/0/-1 $\Leftrightarrow$ left/on line/right.
 * If the optional argument eps$ is given 0 is returned if p$ is within distance eps$ from the line.
 * P is supposed to be Point<T> where T is e.g. double or long long.
 * It uses products in intermediate steps so watch out for overflow if using int or long long.
 * Usage:
 *      bool left = sideOf(p1,p2,q)==1;
 * Status: tested
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

template<class P>
int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

template<class P>
int sideOf(const P& s, const P& e, const P& p, double eps) {
     auto a = (e-s).cross(p-s);
     double l = (e-s).dist()*eps;
     return (a > l) - (a < -l);
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int t;
     cin >> t;
     while(t--){
        Point<ll> a,b,c;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        int ans = sideOf(a,b,c);
        if(ans == -1) cout <<"RIGHT" << endl;
        if(ans == 0)cout <<"TOUCH" << endl;
        if(ans == 1) cout <<"LEFT" << endl;
     }
}