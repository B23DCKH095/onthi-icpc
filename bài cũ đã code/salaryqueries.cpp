#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fenwick Tree implementation
struct Fenwick {
    vector<ll> tree;
    int size;

    Fenwick(int n) : tree(n + 2), size(n) {}

    void update(int pos, int delta) {
        for (; pos <= size; pos += pos & -pos)
            tree[pos] += delta;
    }

    ll query(int pos) {
        ll res = 0;
        for (; pos > 0; pos -= pos & -pos)
            res += tree[pos];
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    vector<tuple<char, ll, ll>> queries(Q);

    // Collect all values for coordinate compression
    vector<ll> all_values;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        all_values.push_back(A[i]);
    }
    for (auto& [type, a, b] : queries) {
        cin >> type >> a >> b;
        if (type == '?') {
            all_values.push_back(a);
            all_values.push_back(b);
        } else {
            all_values.push_back(b);
        }
    }

    // Coordinate compression
    sort(all_values.begin(), all_values.end());
    all_values.erase(unique(all_values.begin(), all_values.end()), all_values.end());
    
    auto compress = [&](ll x) {
        return lower_bound(all_values.begin(), all_values.end(), x) - all_values.begin() + 1;
    };

    // Initialize Fenwick Tree
    Fenwick ft(all_values.size());

    // Insert initial elements
    for (int i = 0; i < N; i++) {
        ft.update(compress(A[i]), 1);
    }

    // Process queries
    for (auto [type, a, b] : queries) {
        if (type == '?') {
            int L = compress(a);
            int R = compress(b);
            cout << ft.query(R) - ft.query(L - 1) << '\n';
        } else {
            int pos = a - 1; // Convert to 0-based
            ft.update(compress(A[pos]), -1);
            A[pos] = b;
            ft.update(compress(A[pos]), 1);
        }
    }

    return 0;
}