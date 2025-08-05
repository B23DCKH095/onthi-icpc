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
     cin >> n >> k;
     vi a(n);
     map<int,int> fre;
     set<int> s;
     for(int i =0 ;i <n ; i++) cin >> a[i];
     for(int i =0 ;i < n; i++) s.insert(i);
     
     for(int i =0 ; i < k ; i++){
        fre[a[i]]++;
        s.erase(a[i]);
     }
     cout << *s.begin() <<" ";
     for(int i = k ; i < n ; i++ ){
        fre[a[i-k]]--;
        if(fre[a[i-k]] == 0) s.insert(a[i-k]);
        if(fre[a[i]] == 0) s.erase(a[i]);
        fre[a[i]]++;
        cout << *s.begin() << " ";
     }
}