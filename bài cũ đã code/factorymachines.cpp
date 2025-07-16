#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,k;
const int maxn =2e5+10;
int a[maxn];
bool check(ll x){
    int s = 0;
    for(int i = 0 ; i< n ; i++) s += x/a[i];
    return s >= k;
}
int main(){
    cin >> n >> k;
    for(int i = 0 ; i < n; i++) cin >> a[i];
    ll l = 0,r = 1;
    while(!check(r)) r*= 2;
    while(l < r){
        ll m = l + (r-l)/2;
        if(check(m)) r = m;
        else l = m+1;
    }
    cout << l << endl;
}