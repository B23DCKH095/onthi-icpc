#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<int, vector<pii>> sum_of_squares;

void precompute(int max_x) {
    int limit = sqrt(max_x) + 1;
    rep(i, 0, limit) {
        rep(j, 0, limit) {
            int sum = i*i + j*j;
            sum_of_squares[sum].push_back({i, j});
        }
    }
}

void solve(int x) {
    for (const auto& entry : sum_of_squares) {
        int m = entry.first;
        int remaining = x - m;
        if (sum_of_squares.count(remaining)) {
            pii pair1 = entry.second[0];
            pii pair2 = sum_of_squares[remaining][0];
            cout << pair1.first << " " << pair1.second << " "
                 << pair2.first << " " << pair2.second << endl;
            return;
        }
    }
    cout << "No solution found for " << x << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int max_possible_x = 1e6; // Adjust based on constraints
    precompute(max_possible_x);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        solve(x);
    }
}