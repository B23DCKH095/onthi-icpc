#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
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
     double angle() const { return atan2(y, x); }
     P unit() const { return *this/dist(); }
     P perp() const { return P(-y, x); }
     P normal() const { return perp().unit(); }
     P rotate(double a) const {
          return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
     friend ostream& operator<<(ostream& os, P p) {
          return os << "(" << p.x << "," << p.y << ")"; }
};
 
template<class P> bool onSegment(P s, P e, P p) {
     return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}
 
typedef Point<ll> P;
template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) {
     int cnt = 0, n = sz(p);
     rep(i,0,n) {
          P q = p[(i + 1) % n];
          if (onSegment(p[i], q, a)) return !strict;
          cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
     }
     return cnt;
}
 
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n, q;
     cin >> n >> q;
     vector<P> v(n);
     for(int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
     while(q--) {
        P p;
        cin >> p.x >> p.y;
        bool boundary = false;
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (onSegment(v[i], v[j], p)) {
                boundary = true;
                break;
            }
        }
        if (boundary) {
            cout << "BOUNDARY\n";
            continue;
        }
        bool inside = inPolygon(v, p, true);
        cout << (inside ? "INSIDE" : "OUTSIDE") << "\n";
     }
}
