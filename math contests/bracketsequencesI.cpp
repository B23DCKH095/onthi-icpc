#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mod =1e9 + 7;
ll exp(int x,int n,int p){
    if(n==0) return 1%p;
    ll u = exp(x,n/2,p);
    u = (u*u)%p;
    if(n%2 ==1) u = (u*x)%p;
    return u;
}
const int maxn =2e6 + 10;
ll fac[maxn+1],inv[maxn+1];
void factorial(){
    fac[0] =1;
    for(int i = 1; i<= maxn ; i++){
        fac[i] = fac[i-1]*i % mod;
    }
}
void inverses(){
    inv[maxn] = exp(fac[maxn],mod-2,mod);
    for(int i = maxn ; i>= 1 ; i--) inv[i-1] = inv[i]*i%mod;
}
ll c(ll n,ll r,ll p){
    return fac[n]*inv[r]%p*inv[n-r]%p;
}
int main(){
    factorial();
    inverses();
    ll n;
    cin >> n;
    if(n%2 == 1){
        cout << 0 << endl;
        return 0;
    }
    n/= 2;
    ll ans = 1;
    ans = (c(2*n,n,mod)*exp(n+1,mod - 2, mod))%mod;
    cout << ans << endl;
}