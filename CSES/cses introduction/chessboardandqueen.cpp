#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


char ch[8][8];
int n;
int cnt;
int column[8],diag1[15],diag2[15];
void search(int y) {
if (y == n) {
cnt++;
return;
}
for (int x = 0; x < n; x++) {
if (column[x] || diag1[x+y] || diag2[x-y+n-1] || ch[x][y] == '*') continue;
column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
search(y+1);
column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
}
}

int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     n = 8;
     for(int i = 0 ;i < 8; i ++){
        for(int j =0 ;j < 8 ;j ++) cin >> ch[i][j];
     }
     search(0);
     cout << cnt << endl;
}