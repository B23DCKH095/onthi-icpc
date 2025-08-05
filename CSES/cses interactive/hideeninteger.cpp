#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int l = 1, r = 1e9;
    while (l < r) {
        int m = l + (r - l) / 2;  // Tránh tràn số
        cout << "? " << m << endl;  // endl tự động flush
        string res;
        cin >> res;
        if (res == "NO") {
            r = m;  // Số cần tìm <= m
        } else {
            l = m + 1;  // Số cần tìm > m
        }
    }

    // In kết quả cuối cùng và flush
    cout << "! " << l << endl;
    return 0;
}