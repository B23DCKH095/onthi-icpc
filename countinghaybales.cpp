#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0 ;i < n; i++) cin >> a[i];
    sort(a.begin() ,a.end());
    while(q--){
        int x,y;
        cin >> x >> y;
        cout <<  upper_bound(a.begin(),a.end(),y) - lower_bound(a.begin() , a.end( ),x) << endl;
    }
}