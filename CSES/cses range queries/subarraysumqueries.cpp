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
void update(int v,int tl,int tr,int pos,ll val){
    if(tl == tr){
        t[v] = make_data(val);
    }
    else{
        int tm = tl + (tr-tl)/2;
        if(pos <= tm) update(2*v,tl,tm,pos,val);
        else update(2*v+1,tm+1,tr,pos,val);
        t[v] = combine(t[2*v],t[2*v+1]);
    }
}
ll query(){
    return t[1].ans;
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
        int pos;
        ll val;
        cin >> pos >> val;
        update(1,0,n-1,pos-1,val);
        cout << query() << endl;
     }
}