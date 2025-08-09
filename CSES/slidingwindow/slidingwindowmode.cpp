#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 2e5 + 10;
int a[maxn];
map<int, int> freq;
set<pair<int, int>> count_set;

void add(int idx) {
    int num = a[idx];
    if (freq.count(num)) {
        count_set.erase({-freq[num], num}); // Using negative for descending order
    }
    freq[num]++;
    count_set.insert({-freq[num], num});
}

void remove(int idx) {
    int num = a[idx];
    count_set.erase({-freq[num], num});
    freq[num]--;
    if (freq[num] == 0) {
        freq.erase(num);
    } else {
        count_set.insert({-freq[num], num});
    }
}

int get_answer() {
    if (count_set.empty()) return 0;
    return count_set.begin()->second; // Returns the number with highest frequency
}

vi mo(vector<pii> queries) {
    int L = 0, R = -1;
    int block_size = sqrt(queries.size()) + 1; // Dynamic block size based on query count
    
    // Create index array and sort based on Mo's order
    vi indices(sz(queries));
    iota(all(indices), 0);
    
    sort(all(indices), [&](int i, int j) {
        int block_i = queries[i].first / block_size;
        int block_j = queries[j].first / block_size;
        if (block_i != block_j) return block_i < block_j;
        return (block_i & 1) ? (queries[i].second > queries[j].second) 
                             : (queries[i].second < queries[j].second);
    });
    
    vi results(sz(queries));
    for (int i : indices) {
        int l = queries[i].first;
        int r = queries[i].second;
        
        // Expand or contract the window
        while (L > l) add(--L);
        while (R < r) add(++R);
        while (L < l) remove(L++);
        while (R > r) remove(R--);
        
        results[i] = get_answer();
    }
    return results;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<pii> queries;
    for (int i = k-1; i < n; i++) {
        queries.push_back({i-k+1, i}); // Window of size k
    }
    
    vi results = mo(queries);
    
    for (int mode : results) {
        cout << mode << " ";
    }
    cout << endl;
    
    return 0;
}