#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    int n;
    cin >> n;
    vector<ll> pre(n+1,0);
    for(int i = 1; i<= n ;i++){
        cin >> pre[i];
        pre[i] = (pre[i] + pre[i-1])%n;
        if(pre[i] < 0) pre[i] += n;
    }
    ll cnt = 0;
    map<ll,ll> mp;
    mp[0]= 1;
    for(int i = 1; i<= n ;i++){
        int c = mp[pre[i]];
        if(c > 0) cnt += c;
        mp[pre[i]]++;
    }
    cout << cnt << endl;
}