#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn =1e5 + 10;
int t[4*maxn];

void add(int v,int tl ,int tr,int l,int r,int val){
    if(l > r) return ;
    if(tl == l && tr == r){
        t[v] = max(t[v],val);
    }
    else{
        int tm = tl + (tr-tl)/2;
        add(2*v,tl,tm,l,min(tm,r),val);
        add(2*v+1,tm+1,tr,max(l,tm+1),r,val);
    }
}
int query(int v,int tl ,int tr,int pos){
    if(tl == tr) return t[v];
    else {
        int tm = tl + (tr-tl)/2;
        if(pos <= tm) return max(t[v],query(2*v,tl,tm,pos));
        else return max(t[v],query(2*v+1,tm+1,tr,pos));
    }
    return 0;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m;
     cin >> n >>m;
     while(m--){
        int t;
        cin>> t;
        if(t==1){
            int l,r,u;
            cin>> l >> r>> u;
            add(1,0,n-1,l,r-1,u);
        }
        else{
            int pos;
            cin >> pos;
            cout << query(1,0,n-1,pos) << endl;
        }
     }
}