#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> sz,p;
int get(int a){
    if(p[a] == a) return a;
    return p[a] = get(p[a]);
}
void unite(int a,int b){
    a = get(a);
    b = get(b);
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    p[b] = a;
}
struct edge{
    int a,b,w;
    friend bool operator < (edge a, edge b){
        return a.w < b.w;
    }
};
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m;
     cin >>n >>m;
     sz.assign(n+1,1);
     p.resize(n+1);
     for(int i = 1; i <= n ; i++)p[i] = i;
     vector<edge> a;
     for(int i = 0 ;i < m ;i++){
        edge e;
        cin >> e.a >> e.b >> e.w;
        a.push_back(e);
     }
     stable_sort(all(a));
     int mst = 0;
     for(int i = 0 ; i<m ; i++){
        edge e = a[i];
        int a,b,w;
        a = e.a ,b = e.b , w =e.w;
        a = get(a);
        b = get(b);
        if(a != b) {
            unite(a,b);
            mst = max(w,mst);
        }
     }
     cout << mst << endl;
}