#include <bits/stdc++.h>
using namespace std;

struct num{
    int v;
    int idx;
    friend bool operator < (num a ,num b){
        return a.v < b.v;
    }
};
int main(){
    int n,x;
    cin >> n >> x;
    num a[n];
    for(int i = 0 ; i < n; i++){
        cin >> a[i].v;
        a[i].idx = i;
    }
    sort(a,a+n);
    int l = 0 , r = n-1;
    while(l < r){
        int s = a[l].v + a[r].v;
        if(s < x) ++l;
        else if(s > x) --r;
        else break;
    }
    if(a[l].v + a[r].v != x || l == r) cout <<"IMPOSSIBLE"<< endl;
    else cout << min(a[l].idx+ 1,a[r].idx + 1) << " "<<max(a[l].idx+ 1,a[r].idx + 1)<< endl;
}