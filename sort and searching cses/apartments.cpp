#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    multiset<int> s;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int cnt = 0;
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        auto it = s.lower_bound(a[i] - k);
        if(it != s.end() && *it <= a[i] + k) {
            cnt++;
            s.erase(it);
        }
    }
    cout << cnt << endl;
}