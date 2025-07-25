#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> order;
    int res = 0; // Josephus(n, k=2) tính từ 0
    for (int i = 2; i <= n; i++) {
        res = (res + 2) % i;
        order.push_back(res + 1); // Chuyển sang đếm từ 1
    }
    for (int x : order) cout << x << " ";
}