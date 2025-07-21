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
 * Source: tinyKACTL
 * Description: Returns twice the signed area of a polygon.
 *  Clockwise enumeration gives negative area. Watch out for overflow if using int as T!
 * Status: Stress-tested and tested on kattis:polygonarea
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

template<class T>
T polygonArea2(vector<Point<T>>& v) {
     T a = v.back().cross(v[0]);
     rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
     return a;
}
typedef Point<ll> P;
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     vector<P> v(n);
     for(int i= 0 ; i<n ; i++) cin>> v[i].x >> v[i].y;
     ll area = abs(polygonArea2(v));
     ll b= 0;
     for(int i =0 ;i <n ; i++){
        int j = (i+1)%n;
        ll dx = abs(v[i].x  - v[j].x);
        ll dy = abs(v[i].y - v[j].y);
        b += __gcd(dx,dy)+1;
     }
     b-= n;
     ll a = (area + 2 - b)/2;
     cout << a<<" "<< b << endl;
}