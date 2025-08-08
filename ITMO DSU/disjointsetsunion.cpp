#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn =1e5 + 10;
int p[maxn];
unordered_set<int> l[maxn];
void init(int n){
    for(int i =1; i <= n ; i++){
        p[i] = i;
        l[i] = {i};
    }
}
int get(int a){
    return p[a];
}
void unite(int a,int b){
    a = p[a];
    b = p[b];
    if(a==b) return;
    if(sz(l[a]) > sz(l[b])) swap(a,b);
    for(int x : l[a]){
        p[x] = b;
    }
    l[b].insert(all(l[a]));
    l[a].clear();
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m;
     cin >>n >> m;
     init(n);
     for(int i = 0 ; i < m ; i++){
        string t;
        cin >> t;
        if(t== "union"){
            int a,b;
            cin >> a >> b;
            unite(a,b);
        }else{
            int a,b;
            cin >> a >> b;
            if(get(a) == get(b)) cout <<"YES"<< endl;
            else cout <<"NO" << endl;
        }
     }
}