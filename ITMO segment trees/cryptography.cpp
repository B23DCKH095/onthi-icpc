#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef array<ll,4> ar;
array<ll, 4> mul(array<ll, 4> a, array<ll, 4> b,int mod)
{
    array<ll, 4> res;
    res[0] = ((a[0] * b[0]) % mod + (a[1] * b[2]) % mod) % mod;
    res[1] = ((a[0] * b[1]) % mod + (a[1] * b[3]) % mod) % mod;
    res[2] = ((a[2] * b[0]) % mod + (a[3] * b[2]) % mod) % mod;
    res[3] = ((a[2] * b[1]) % mod + (a[3] * b[3]) % mod) % mod;
    return res;
}
int mod,n,m;
const int maxn = 2e5 + 10;
ar t[4*maxn];

void build(ar a[] , int v,int tl ,int tr){
    if(tl == tr){
        t[v] = a[tl];
    }
    else {
        int tm = tl + (tr-tl)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        t[v] = mul(t[2*v],t[2*v+1],mod);
    }
}
ar query(int v,int tl,int tr,int l,int r){
    if(l > tr || r < tl) return {1,0,0,1};
    if(l == tl &&r == tr) return t[v];
    int tm = tl + (tr-tl)/2;
    return mul(query(2*v,tl,tm,l,min(r,tm)), query(2*v+1,tm+1,tr,max(l,tm+1),tr),mod);
}
void update(int v,int tl,int tr,int pos,ar val){
    if(tl == tr){
        t[v] = val; 
    }
    else{
        int tm = tl + (tr-tl)/2;
        if(pos <= tm) update(2*v,tl,tm,pos,val);
        else update(2*v+1,tm+1,tr,pos,val);
        t[v] = mul(t[2*v],t[2*v+1],mod);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> mod >> n >> m;
    ar a[n];
    for(int i = 0; i <n ; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        a[i][0] %= mod;
        a[i][1] %= mod;
        a[i][2] %= mod;
        a[i][3] %= mod;
    }
    build(a,1,0,n-1);
    while(m--){
        int l,r;
        cin >> l >> r;
        --l,--r;
        ar res = query(1,0,n-1,l,r);
        cout << res[0] <<" "<< res[1] << endl;
        cout << res[2] <<" "<< res[3] << endl;
        cout << endl;
    }
}