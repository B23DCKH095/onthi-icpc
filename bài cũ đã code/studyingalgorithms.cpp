#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    int a[n];
    for(int i = 0 ;i <n ; i++) cin >> a[i];
    sort(a,a+n);
    int cnt  = 0;
    for(int i = 0 ; i < n ;i++){
        if(a[i] <= x){
            x -= a[i];
            ++ cnt;
        }
    }
    cout << cnt << endl;
}