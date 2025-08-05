#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mod = 1e9 + 7;
template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
            rep(k,0,N) a.d[i][j] = (a.d[i][j]+  d[i][k]*m.d[k][j])%mod;
        return a;
    }
    array<T, N> operator*(const array<T, N>& vec) const {
        array<T, N> ret{};
        rep(i,0,N) rep(j,0,N) ret[i] =(ret[i] +  d[i][j] * vec[j])%mod;
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i,0,N) a.d[i][i] = 1;
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p >>= 1;
        }
        return a;
    }
};

int main() {
    array<ll, 6> vec = {1,2,4,8,16,32};
    Matrix<ll, 6> A;
    A.d = {{
        {{0,1,0,0,0,0}},
        {{0,0,1,0,0,0}},
        {{0,0,0,1,0,0}},
        {{0,0,0,0,1,0}},
        {{0,0,0,0,0,1}},
        {{1,1,1,1,1,1}}
    }};
    ll n;
    cin >> n;
    if( n <= 6){
        cout << vec[n-1] << endl;
        return 0;
    }
    vec = (A^(n-6))*vec;
    cout << vec[5] << endl;
}