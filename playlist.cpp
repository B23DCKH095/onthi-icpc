#include <bits/stdc++.h>
using namespace std;
 
const int maxn =2e5 + 10;
vector<int> coordinate_compression(vector<int>& arr) {
    vector<int> sorted_arr = arr;
    
    // Bước 1: Sắp xếp và loại bỏ trùng lặp
    sort(sorted_arr.begin(), sorted_arr.end());
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
    
    // Bước 2: Ánh xạ mỗi giá trị về chỉ số của nó
    vector<int> compressed;
    for (int num : arr) {
        int idx = lower_bound(sorted_arr.begin(), sorted_arr.end(), num) - sorted_arr.begin();
        compressed.push_back(idx);
    }
    
    return compressed;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> a = coordinate_compression(b);
    vector<bool> seen(maxn,false);
    int left = 0, max_len = 0;
    for (int right = 0; right < n; ++right) {
        while (seen[a[right]]) {
            seen[a[left]] = false;
            ++left;
        }
        seen[a[right]] = true;
        max_len = max(max_len, right - left + 1);
    }
    cout << max_len << endl;
    return 0;
}