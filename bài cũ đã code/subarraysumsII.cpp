#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    map<ll,ll> se;
    int n,x;
    cin >> n >> x;
    vector<ll> pre(n+1,0);
    for(int i = 1; i<= n ;i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    ll cnt =0;
    for(int i =1; i<= n ;i++){
        int c = se[pre[i] - x];
        if(c > 0) cnt +=c;
        if(pre[i] == x) ++ cnt;
        se[pre[i]]++;
    }
    cout << cnt << endl;
}