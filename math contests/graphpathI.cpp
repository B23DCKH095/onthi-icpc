#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 1e9 + 7;
const int MAX_N = 105; // Số đỉnh tối đa

template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N) {
            rep(k,0,N) {
                a.d[i][j] = (a.d[i][j] + d[i][k] * m.d[k][j]) % mod;
            }
        }
        return a;
    }
    array<T, N> operator*(const array<T, N>& vec) const {
        array<T, N> ret{};
        rep(i,0,N) rep(j,0,N) {
            ret[i] = (ret[i] + d[i][j] * vec[j]) % mod;
        }
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i,0,N) a.d[i][i] = 1; // Ma trận đơn vị
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
    
    // Kiểm tra kích thước đồ thị
    if (n > MAX_N) {
        cout << "Number of vertices exceeds maximum limit\n";
        return 1;
    }
    
    // Khởi tạo ma trận kề với tất cả phần tử = 0
    Matrix<ll, MAX_N> mat;
    rep(i,0,MAX_N) rep(j,0,MAX_N) mat.d[i][j] = 0;
    
    // Đọc các cạnh
    rep(i,0,m) {
        int x, y;
        cin >> x >> y;
        --x; --y; // Chuyển về 0-based
        ++mat.d[x][y];
    }
    
    // Tính mat^k để tìm số đường đi độ dài k
    auto result = mat^k;
    
    // In số đường đi độ dài k từ đỉnh 0 đến đỉnh n-1
    cout << result.d[0][n-1] << endl;
    
    return 0;
}