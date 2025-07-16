#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;
ll a[maxn];

// Returns true if C(n, k) is odd
bool is_comb_odd(int n, int k) {
    return (n & k) == k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        // Check if C(n-1, i-1) is odd using Lucas' theorem
        if(is_comb_odd(n - 1, i - 1)) {
            ans ^= a[i];
        }
    }
    cout << ans << endl;
    return 0;
}