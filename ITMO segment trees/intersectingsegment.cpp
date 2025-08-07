#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 2e5 + 10;
int t[4*maxn];
void update(int v,int tl,int tr,int pos,int val){
    if(tl == tr){
        t[v] =val;
    }
    else{
        int tm = tl + (tr-tl)/2;
        if(pos <= tm) update(2*v,tl,tm,pos,val);
        else update(2*v+1,tm+1,tr,pos,val);
        t[v] = t[2*v] + t[2*v+1];
    }
}
int query(int v,int tl,int tr,int  l,int r){
    if(l > tr || r < tl) return 0;
    if(l == tl && r == tr) return t[v];
    int tm = tl + (tr-tl)/2;
    return query(2*v,tl,tm,l,min(r,tm)) + query(2*v+1,tm+1,tr,max(l,tm+1),r);
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin>> n;
     n*= 2;
     int a[n];
     for(int i = 0 ; i<n ; i++){
        cin>> a[i];
     }
     map<int,int> mp;
     vector<int> v(n/2);
     for(int i = 0 ; i< n; i++){
        if(!mp[a[i]]) {
            mp[a[i]] = i+1;
            update(1,0,2*n-1,i,1);
        }
        else{
            int ret = query(1,0,2*n-1,mp[a[i]],i);
            update(1,0,2*n-1,mp[a[i]]-1,0);
            v[a[i]-1] += ret;
        }
     }
     reverse(a,a+n);
     mp.clear();
     for(int i = 0 ; i< n; i++){
        if(!mp[a[i]]) {
            mp[a[i]] = i+1;
            update(1,0,2*n-1,i,1);
        }
        else{
            int ret = query(1,0,2*n-1,mp[a[i]],i);
            update(1,0,2*n-1,mp[a[i]]-1,0);
            v[a[i]-1] += ret;
        }
     }
     for(int i = 0 ; i<n/2 ; i++) cout << v[i]<<" ";
}