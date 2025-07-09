#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type,less<pair<int,int>> ,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(){
    int n,k;
    cin >> n >>k;
    indexed_set s;
    int a[n];
    for(int i = 0 ; i< n ;i++) cin >> a[i];
    for(int i = 0 ;i < k ; i++) s.insert({a[i],i});
    vector<int> ret;
    ret.push_back(s.find_by_order((k-1)/2)->first);
    for(int i = k ; i< n ; i++){
        s.erase({a[i-k],i-k});
        s.insert({a[i],i});
        ret.push_back(s.find_by_order((k-1)/2)->first);
    }
    for(int x : ret) cout << x <<" ";
}