#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
    int n = sz(gr);
    vi D(n), its(n), eu(nedges), ret, s = {src};
    D[src]++; // to allow Euler paths, not just cycles
    while (!s.empty()) {
        int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
        if (it == end){ ret.push_back(x); s.pop_back(); continue; }
        tie(y, e) = gr[x][it++];
        if (!eu[e]) {
            D[x]--, D[y]++;
            eu[e] = 1; s.push_back(y);
        }
    }
    for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
    return {ret.rbegin(), ret.rend()};
}

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

const int maxn = 2e5 + 10;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    map<pii,int> mp;
    vector<pair<pii,pii>> v(n);
    int cnt = 0;  // Changed from -1 to 0 since we're using 0-based indexing
    
    // Initialize edges with enough space
    vector<vector<pii>> edges(2*n);  // At most 2n distinct points
    
    for(int i = 0; i < n; i++) {
        pii x, y;
        cin >> x.first >> x.second >> y.first >> y.second;
        
        // Assign indices to points if they haven't been seen before
        if(mp.find(x) == mp.end()) mp[x] = cnt++;
        if(mp.find(y) == mp.end()) mp[y] = cnt++;
        
        v[i] = {x, y};
        
        // Add edges in both directions with the same edge index
        edges[mp[x]].emplace_back(mp[y], i);
        edges[mp[y]].emplace_back(mp[x], i);
    }
    
    // The number of edges is n (since each input line represents one edge)
    vi ans = eulerWalk(edges, n, 0);
    
    if(ans.empty()) {
        cout << "No Eulerian path/cycle exists" << endl;
    } else {
        for(int x : ans) cout << x << " ";
        cout << endl;
    }
    
    return 0;
}