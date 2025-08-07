#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int maxn = 1e5 + 10;
ll t[4*maxn];
void update(int v,int tl,int tr,int pos,int val){
    if(tl == tr){
        t[v] += val;
    }
    else{
        int tm = tl + (tr-tl)/2;
        if(pos <= tm) update(2*v,tl,tm,pos,val);
        else update(2*v+1,tm+1,tr,pos,val);
        t[v]  =t[2*v] + t[2*v+1];
    }
}
ll sum(int v,int tl,int tr,int l,int r){
    if(l > tr || r < tl) return 0;
    if(l == tl && r == tr) return t[v];
    int tm = tl + (tr-tl)/2;
    return sum(2*v,tl,tm,l,min(r,tm)) + sum(2*v+1,tm+1,tr,max(l,tm+1),r);
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m;
     cin>>n >> m;
     for(int i = 0 ; i< m ; i++){
        int t;
        cin>> t;
        if(t==1){
            int l,r,v;
            cin>> l >> r >> v;
            update(1,0,n-1,l,v);
            if(r < n) update(1,0,n-1,r,-v);
        }
        else{
            int pos;
            cin >> pos;
            cout << sum(1,0,n-1,0,pos) << endl;
        }
     }
}