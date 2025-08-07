#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 10;
int t[4*maxn],a[maxn];
void build(int a[],int v,int tl,int tr){
    if(tl == tr){
        t[v] = a[tl];
    }
    else {
        int tm = tl + (tr- tl)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        t[v] = t[2*v] +t[2*v+1];
    }
}
void update(int v,int tl,int tr,int pos){
    if(tl == tr){
        t[v] = 0;
    }
    else{
        int tm = tl + (tr-tl)/2;
        if(pos <= tm) update(2*v,tl,tm,pos);
        else update(2*v+1,tm+1,tr,pos);
        t[v] = t[2*v]+t[2*v+1];
    }
}
int query(int v,int tl,int tr,int k){
    if(k > t[v]) return -1;
    if(tl == tr) return tl;
    int tm = tl + (tr-tl)/2;
    if(t[2*v] >= k){
        int left = query(2*v,tl,tm,k);
        if(left != -1) return left;
    }
    return query(2*v+1,tm+1,tr,k - t[2*v]);
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     int b[n];
     for(int i = 0 ; i<n ;i++){
        cin >> b[i];
        a[i] = 1;
     }
     int m = n;
     build(a,1,0,n-1);
     vector<int> res;
     for(int i = n-1; i >= 0 ; i--){
        int ret  =  query(1,0,n-1,m-b[i]) ;
        res.push_back(ret+1);
        m--;
        update(1,0,n-1,ret);
     }
     reverse(all(res));
     for(int x : res) cout << x << " ";
}