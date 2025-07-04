#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;

ll tree[maxn],a[maxn];
int n;

ll sum(int k){
    int s = 0;
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
    for(int i = 1; i <= n ;i++){
        cin >> a[i];
        add(i,a[i]);
    }
    while(q--){
        char t;
        cin >> t;
        if(t=='!'){
            int k,v;
            cin >> k >> v;
            add(k , -a[k]);
            a[k] = v;
            add(k,v);
        }
        else {
            int a,b;
            cin >> a >> b;
            cout << sum(b) - sum(a-1)<< endl;
        }
    }
}