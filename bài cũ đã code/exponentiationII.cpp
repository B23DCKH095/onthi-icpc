#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(int x,int p,int mod){
    if(p==0) return 1%mod;
    ll u = calc(x,p/2,mod);
    u = (u*u)% mod;
    if(p%2 == 1) u = (u * x)%mod;
    return u;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int m = 1e9 + 7;
        ll x = calc(b,c,m-1);
        cout << calc(a,x,m)<< endl;
    }
}