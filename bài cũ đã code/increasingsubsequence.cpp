#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i<n ; i++) cin >> a[i];
    vector<int> tails;
    for(int i = 0 ; i < n ;i++){
        auto it = lower_bound(tails.begin() , tails.end() , a[i]);
        if(it == tails.end()) tails.push_back(a[i]);
        else *it  = a[i];
    }
    cout << tails.size()<< endl;
}