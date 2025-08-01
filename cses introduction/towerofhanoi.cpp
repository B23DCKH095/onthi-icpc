#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void f(int a,int b,int c,int n){
    if(n== 0) return;
    f(a,c,b,n-1);
    cout << a <<" "<< c << endl;
    f(b,a,c,n-1);
    return;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n;
     cin >> n;
     cout << pow(2,n)-1 << endl;
     f(1,2,3,n);
}