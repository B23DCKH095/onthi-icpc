#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> p;
int n;
int get(int a){
    if(p[a] == a) return a;
    return p[a] = get(p[a]);
}
void unite(int a,int b){
    a = get(a);
    b = get(b);
    p[a] = b%(n);
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     cin >> n;
     int a[n];
     p.resize(n+1);
     for(int i = 1; i<= n ; i++) p[i] =i;
     for(int i = 0 ;i <n ; i ++){
        int x;
        cin >> x;
        x%= n;
        x= get(x);
        if(x==0) cout << n <<" ";
        else cout << x << " ";
        unite(x,x+1);
     }
}