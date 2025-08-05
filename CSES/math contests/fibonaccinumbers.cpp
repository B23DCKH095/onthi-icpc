#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1e9 + 7;
template<class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(const M& m) const {
		M a;
		rep(i,0,N) rep(j,0,N)
			rep(k,0,N) a.d[i][j] =(a.d[i][j] +  d[i][k]*m.d[k][j])%MOD;
		return a;
	}
	array<T, N> operator*(const array<T, N>& vec) const {
		array<T, N> ret{};
		rep(i,0,N) rep(j,0,N) ret[i] = (ret[i] +  d[i][j] * vec[j])%MOD;
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
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     long long n;
     cin >> n;
     if(n==0){
        cout << 0 << endl;
        return 0;
     }
     Matrix<ll,2> M;
     M.d = {{{1,1},{1,0}}};
     M = M^(n-1);
     array<ll,2> res = {1,0};
     res = M*res;
     cout << res[0]<< endl;

}
