#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
                 tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    Tree<pair<int, int>> t;  // Stores {value, index} to handle duplicates
    map<int, int> count;     // Tracks counts of each value in current window
    
    // Initialize first window
    for(int i = 0; i < k; i++) {
        t.insert({a[i], i});
        count[a[i]]++;
    }
    
    // Get initial median
    auto it = t.find_by_order((k-1)/2);
    cout << it->first;
    
    // Slide window
    for(int i = k; i < n; i++) {
        // Remove leftmost element (a[i-k])
        int left_val = a[i-k];
        auto left_it = t.lower_bound({left_val, 0});
        if(left_it != t.end() && left_it->first == left_val) {
            t.erase(left_it);
        }
        count[left_val]--;
        if(count[left_val] == 0) {
            count.erase(left_val);
        }
        
        // Add new element (a[i])
        t.insert({a[i], i});
        count[a[i]]++;
        
        // Get median
        it = t.find_by_order((k-1)/2);
        cout << " " << it->first;
    }
    
    return 0;
}