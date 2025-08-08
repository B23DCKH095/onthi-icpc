#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> p,sz;
int get(int a){
    if(p[a] ==a) return a;
    return p[a] = get(p[a]);
}
void unite(int a,int b){
    a = get(a);
    b = get(b);
    p[a] = b;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m;
     cin >> n >>m;
     p.resize(n+2);
     sz.resize(n+1);
     for(int i = 1; i <= n ;i++){
        p[i] = i;
        sz[i] = 1;
    }
    while(m--){
        char c;
        int a;
        cin >> c >> a;
        if(c=='?'){
            a = get(a);
            if(a==0) cout << -1 << endl;
            else cout << a << endl;
        }
        if(c == '-'){
            a = get(a);
            if(a != n+1) unite(a,a+1);
        }
    }
}