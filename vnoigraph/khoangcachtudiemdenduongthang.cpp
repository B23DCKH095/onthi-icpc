#include <bits/stdc++.h>
using namespace std;

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

template<class P>
double lineDist(const P& a, const P& b, const P& p) {
    return (double)(b-a).cross(p-a)/(b-a).dist();
}

int main() {
    Point<double> a, b, c;
    cin >> a.x >> a.y;
    
    double A, B, C;  // Changed from int to double for line coefficients
    cin >> A >> B >> C;
    
    // Find two points on the line Ax + By + C = 0
    if (B != 0) {
        // When x=0, y=-C/B
        b = Point<double>(0, -C/B);
        // When x=1, y=(-A-C)/B
        c = Point<double>(1, (-A-C)/B);
    } else {
        // Vertical line (B=0): Ax + C = 0 => x = -C/A
        b = Point<double>(-C/A, 0);
        c = Point<double>(-C/A, 1);
    }
    
    double ans = lineDist(b, c, a);
    cout << fixed << setprecision(6) << ans << endl;
}