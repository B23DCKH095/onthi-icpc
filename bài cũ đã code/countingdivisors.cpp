#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int ret  = 0;
    for(int i =1; i*i <= n ; i++){
        if(n%i == 0){
            if(i*i == n) ret += 1;
            else ret += 2;
        }
    }
    cout << ret << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}