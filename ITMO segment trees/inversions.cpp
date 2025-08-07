#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn =1e5  +10;
int t[4*maxn];
void update(int v,int tl,int tr,int pos){
    if(tl == tr){
        t[v] = 1;
    }
    else{
        int tm = tl + (tr- tl)/2;
        if(pos <= tm) update(2*v,tl,tm,pos);
        else update(2*v+1,tm+1,tr,pos);
        t[v] = t[2*v] + t[2*v+1];
    }
}
int query(int v,int tl,int tr,int l,int r){
    if(l > r) return 0;
    if(l == tl && r == tr) return t[v];
    int tm = tl + (tr-tl)/2;
    return query(2*v,tl,tm,l,min(r,tm)) + query(2*v+1,tm+1,tr,max(l,tm+1),r);
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     int a[n];
     for(int i = 0 ; i<n ; i++){
        cin >> a[i];
        --a[i];
     }
     for(int i = 0 ; i<n ; i++){
        cout << query(1,0,n-1,a[i],n-1) <<" ";
        update(1,0,n-1,a[i]);
     }
}