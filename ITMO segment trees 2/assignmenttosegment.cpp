#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn =1e5 + 10;
int t[4*maxn],marked[4*maxn];
void push(int v){
    if(marked[v]){
        t[2*v] = t[2*v+1] = t[v];
        marked[2*v] = marked[2*v+1] = true;
        marked[v] = false;
    }
}
void update(int v,int tl,int tr,int l,int r,int val){
    if(l > r) return;
    if(tl == l && r == tr) {
        t[v] = val;
        marked[v] = true;
    }
    else{
        push(v);
        int tm = tl + (tr-tl)/2;
        update(2*v,tl,tm,l,min(r,tm),val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,val);
    }
}
int get(int v,int tl,int tr,int pos){
    if(tl == tr){
        return t[v];
    }
    else{
        push(v);
        int tm = tl +(tr-tl)/2;
        if(pos <= tm) return get(2*v,tl,tm,pos);
        else return get(2*v+1,tm+1,tr,pos);
    }
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m;
     cin >> n >> m;
     while(m--){
        int t;
        cin >> t;
        if(t==1){
            int l,r,u;
            cin >> l >> r >> u;
            update(1,0,n-1,l,r-1,u);
        }
        else{
            int pos;
            cin >> pos;
            cout << get(1,0,n-1,pos) << endl;
        }
     }
}