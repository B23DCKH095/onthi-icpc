#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> p(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
    }

    vector<char> dp(n + 1, 'L'); // Khởi tạo tất cả là 'L'
    dp[0] = 'L'; // Base case

    for (int i = 1; i <= n; ++i) {
        for (int move : p) {
            if (i >= move && dp[i - move] == 'L') {
                dp[i] = 'W';
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dp[i];
    }
    cout << endl;

    return 0;
}