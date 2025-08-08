#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct edges{
    string t;
    int a,b;
};
vector<int> p,sz;
int get(int a){
    if(p[a] == a) return a;
    return p[a] = get(p[a]);
}
void unite(int a,int b){
    a  = get(a);
    b = get(b);
    if(a==b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
    int n,m,q;
    cin >> n >> m >> q;
    sz.resize(n+1);
    p.resize(n+1);
    for(int i =1; i <= n ; i++){
        p[i] = i;
        sz[i] = 1;
    }
    map<pair<int,int>,bool> mp;
    for(int i = 0 ; i<m ; i++){
        int a,b;
        cin >> a >> b;
        mp[{a,b}] = true;
        mp[{b,a}] = true;
    }
    vector<edges> v(q);
    for(int i = 0 ; i<q; i++){
        edges u;
        cin >> u.t >> u.a >> u.b;
        v[i] = u;
    }
    vector<string> ans;
    for(int i = q-1; i >= 0; i--){
        edges u = v[i];
        if(u.t == "ask"){
            int a,b;
            a = u.a , b = u.b;
            if(get(a) == get(b)) ans.push_back("YES");
            else ans.push_back("NO");
        }
        else{
            int a,b;
            a = u.a , b = u.b;
            if(mp[{a,b}]){
                unite(a,b);
                mp[{a,b}] = mp[{b,a}] = false;
            }
        }
    }
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << endl;
}