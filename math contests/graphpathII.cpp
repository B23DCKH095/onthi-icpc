#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll INF = 1e18 + 7;
const int MAX_N = 105; // Maximum number of vertices

template<int N> struct Matrix {
    typedef Matrix M;
    array<array<ll, N>, N> d{};
    
    // Min-plus (tropical) matrix multiplication
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N) {
            a.d[i][j] = INF;
            rep(k,0,N) {
                if (d[i][k] != INF && m.d[k][j] != INF) {
                    a.d[i][j] = min(a.d[i][j], d[i][k] + m.d[k][j]);
                }
            }
        }
        return a;
    }
    
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        // Identity matrix for min-plus: 0 on diagonal, INF elsewhere
        rep(i,0,N) rep(j,0,N) a.d[i][j] = (i == j) ? 0 : INF;
        while (p) {
            if (p&1) a = a * b;
            b = b * b;
            p >>= 1;
        }
        return a;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    if (n > MAX_N) {
        cout << "Number of vertices exceeds maximum limit\n";
        return 1;
    }
    
    Matrix<MAX_N> mat;
    // Initialize with INF (no edges)
    rep(i,0,MAX_N) rep(j,0,MAX_N) mat.d[i][j] = INF;
    
    // Read edges
    rep(i,0,m) {
        int x, y, c;
        cin >> x >> y >> c;
        --x; --y; // Convert to 0-based
        mat.d[x][y] = c;
    }
    
    auto result = mat^k;
    
    // Print shortest path of exactly k edges from 0 to n-1
    if (result.d[0][n-1] == INF) {
        cout << -1 << endl; // No path exists
    } else {
        cout << result.d[0][n-1] << endl;
    }
    
    return 0;
}