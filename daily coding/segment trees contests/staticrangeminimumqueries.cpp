#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> seg;
const int INF = INT_MAX;

void build(int _n){
    n = _n;
    seg.assign(2*n,INF);
}
void update(int pos,int val){
    for(seg[pos += n] = val ; pos > 1 ; pos >>= 1){
        seg[pos >> 1] = min(seg[pos], seg[pos^1]);
    }
}
int query(int l,int r){
    int res = INF;
    for(l += n , r += n ; l < r ; l >>= 1 , r >>= 1){
        if(l&1) res = min(res,seg[l++]);
        if(r&1) res = min(res,seg[--r]);
    }
    return res;
}
int main(){
    int q;
    cin >> n >> q;
    build(n);
    int a[n];
    for(int i = 0 ;i < n; i++) {
        cin >> a[i];
        update(i,a[i]);
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << query(l-1,r)<< endl;
    }
}