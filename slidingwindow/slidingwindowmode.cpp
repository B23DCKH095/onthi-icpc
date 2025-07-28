#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
     int n,k;
     cin >> n >>k;
     vector<int> v(n);
     for(int i = 0 ; i<n ; i++) cin >> v[i];
     vi arr = coordinate_compression(v);
    //  for(int i =0 ;i <n ; i++) cout << arr[i] <<" ";
    map<int,int> ax;
    for(int i = 0 ;i <n ; i++) ax[arr[i]] = v[i];
     map<int,int> mp;
     int cnt = 0;
     vector<int> ret;
     int cur = 0;
     for(int i = 0 ; i < k ; i++){
        if(mp[arr[i]] == mp[cur]) cur = min(arr[i] , cur);
        else if(mp[arr[i]] > mp[arr[cur]]) cur = arr[i];
     }
     ret.push_back(cur);
     for(int i = k ; i < n ; i++){
        --mp[arr[i-k]];
        ++mp[arr[i]];
        if(mp[arr[i]] == mp[cur]) cur = min(arr[i] , cur);
        else if(mp[arr[i]] > mp[arr[cur]]) cur = arr[i];
        ret.push_back(cur);
     }
     for(int x : ret) cout << ax[x]<< " ";
}