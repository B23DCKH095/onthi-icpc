#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn =1e5 + 10;
int n,t[4*maxn];
void build(int a[],int v,int tl,int tr){
    if(tl == tr){
        t[v] = a[tl];
    }
    else {
        int tm = tl + (tr - tl)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        t[v] = max(t[2*v] , t[2*v+1]);
    }
}
int query(int v,int tl,int tr,int x){
    if(t[v] < x) return -1;
    if(tl == tr) return tl;
    int tm = tl + (tr-tl)/2;
    if(t[2*v] >= x) {  // Check left child first
        return query(2*v, tl, tm, x);
    } else {
        return query(2*v+1, tm+1, tr, x);
    }
}
void update(int v,int tl,int tr,int pos,int val){
    if(tl == tr){
        t[v] = val;
    }
    else{
        int tm = tl + (tr-tl)/2;
        if(pos <= tm) update(2*v,tl,tm,pos,val);
        else update(2*v+1,tm+1,tr,pos,val);
        t[v] = max(t[2*v],t[2*v+1]);
    }
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int q;
     cin >> n >> q;
     int a[n];
     for(int i = 0 ; i <n ; i++) cin >> a[i];
     build(a,1,0,n-1);
     while(q--){
        int t;
        cin >> t;
        if(t==1){
            int u,v;
            cin >> u >> v;
            update(1,0,n-1,u,v);
        }
        else {
            int x;
            cin >> x;
            cout << query(1,0,n-1,x)<< endl;
        }
     }
}