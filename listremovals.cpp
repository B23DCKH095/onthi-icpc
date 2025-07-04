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
    cin >> n;
    for(int i = 1; i<= n ;i++){
        cin >> a[i];
        add(i,1);
    }
    for(int i =1; i <=  n ; i++){
        int x;
        cin >> x;
        int l = 1, r = n;
        while(l < r){
            int m = l + (r-l)/2;
            if(x <= sum(m)) r = m;
            else l = m+1;
        }
        cout << a[l]<< " ";
        add(l,-1);
    }
}