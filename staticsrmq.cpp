#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXLOG = 20;

vector<int> values;
vector<vector<int>> sparse_table;

// Precompute floor(log2) values
vector<int> log_table;

void build_log_table(int n) {
    log_table.resize(n + 1);
    log_table[1] = 0;
    for (int i = 2; i <= n; i++) {
        log_table[i] = log_table[i/2] + 1;
    }
}

// Compare function - returns index with smaller value
int better_index(int a, int b) {
    return values[a] == values[b] ? min(a, b) : 
           (values[a] < values[b] ? a : b);
}

void build_rmq(const vector<int>& data) {
    values = data;
    int n = values.size();
    int max_log = log2(n) + 1;
    
    build_log_table(n);
    
    sparse_table.assign(max_log, vector<int>(n));
    
    // Initialize for length 1 ranges
    iota(sparse_table[0].begin(), sparse_table[0].end(), 0);
    
    // Build sparse table
    for (int j = 1; j < max_log; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            sparse_table[j][i] = better_index(
                sparse_table[j-1][i],
                sparse_table[j-1][i + (1 << (j-1))]
            );
        }
    }
}

int query_index(int l, int r) {
    int len = r - l + 1;
    int k = log_table[len];
    return better_index(
        sparse_table[k][l],
        sparse_table[k][r - (1 << k) + 1]
    );
}

int query_value(int l, int r) {
    return values[query_index(l, r)];
}

int main() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0 ; i< n ; i++) cin >> a[i];
    build_rmq(a);
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << query_value(l,r-1)<< endl;
    }
    return 0;
}