#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct seg{
    ll sum,pref,suff,ans;
};
seg make_data(ll val){
    seg res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0LL,val);
    return res;
}
seg combine(seg a,seg b){
    seg res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref , a.sum + b.pref);
    res.suff = max(b.suff, a.suff + b.sum);
    res.ans = max({a.ans,b.ans,a.suff + b.pref});
    return res;
}
const int maxn = 2e5 + 10;
seg t[4*maxn];
void build(ll a[],int v,int tl ,int tr){
    if(tl == tr){
        t[v] = make_data(a[tl]);
        return;
    }
    else{
        int tm = tl + (tr-tl)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        t[v] = combine(t[2*v] , t[2*v+1]);
    }
}
seg query(int v,int tl,int tr,int l,int r){
    if(l > r) return make_data(0);
    if(l == tl && r == tr) return t[v];
    else{
        int tm = tl + (tr-tl)/2;
        seg left = query(2*v,tl,tm,l,min(r,tm));
        seg right = query(2*v+1,tm+1,tr,max(tm+1,l),r);
        return combine(left,right);
    }
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,q;
     cin >>n >> q;
     ll a[n];
     for(int i = 0 ; i <n ; i++) cin >> a[i];
     build(a,1,0,n-1);
     while(q--){
        int l,r;
        cin >> l >> r;
        --l ,--r;
        seg ans = query(1,0,n-1,l,r);
        cout << ans.ans << endl;
     }
}