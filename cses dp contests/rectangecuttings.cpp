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
     int a,b;
     cin >> a >> b;
     int move = 0;
     while(a!= 1 || b!= 1){
        int x = min(a,b);
        if(a > b) a-= x;
        else if(b > a) b-= x;
        else if(a==b) break;
        ++ move;
     }
     cout << move << endl;
}