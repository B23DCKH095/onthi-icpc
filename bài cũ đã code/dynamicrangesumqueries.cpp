#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
ll tree[maxn], a[maxn];
int n;
ll sum(int k){
    ll s = 0;
    while(k >= 1){
        s+= tree[k];
        k -= k&-k;
    }
    return s;
}
void add(int k,int x){
    while(k <= n){
        tree[k] +=x;
        k += k&-k;
    }
}

int main(){
    int q;
    cin >> n >> q;
    for(int i = 1 ; i<= n ; i++){
        int x;
        cin >> x;
        a[i] = x;
        add(i,x);
    }
    while(q--){
        int t,u,v;
        cin >> t >> u >> v;
        if(t==1){
            add(u,-a[u]);
            a[u] = v;
            add(u,v);
        } else {
            cout << sum(v)  -sum(u-1) << endl;
        }
    }
}