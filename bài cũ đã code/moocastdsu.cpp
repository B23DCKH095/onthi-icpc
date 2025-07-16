#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1001;
ll calc(pair<int,int> a,pair<int,int> b){
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second) * (a.second -b.second);
}
ll d[maxn][maxn];
int sz[maxn],p[maxn];

int find(int x){
    while(x != p[x]) x = p[x];
    return x;
}
bool same(int a,int b){
    return find(a) == find(b);
}
void unite(int a,int b){
    a = find(a);
    b = find(b);
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    p[b] = a;
}
int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0 ; i< n ; i++){
        sz[i] = 1;
        p[i] = i;
    }
    vector<pair<int,int>> a(n);
    priority_queue<pair<ll,pair<int,int>>> q;
    for(int i = 0 ;i <n ; i++) cin >> a[i].first >> a[i].second;
    for(int i = 0; i< n; i++){
        for(int j = i+ 1; j < n ; j++){
            d[i][j] = calc(a[i] ,a[j]);
            q.push({-d[i][j] ,{i,j}});
        }
    }
    ll ans = 0;
    while(!q.empty()){
        auto u = q.top();
        q.pop();
        ll w ;
        int x,y;
        w = -u.first, x = u.second.first, y = u.second.second;
        if(!same(x,y)){
            ans = max(ans,w);
            unite(x,y);
        }
    }
    cout << ans << endl;
}