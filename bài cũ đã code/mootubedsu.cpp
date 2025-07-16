#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
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
struct edge{
    int a,b,w;
    friend bool operator < (edge a,edge b){
        return a.w < b.w;
    }
};
struct q{
    int k,v,i;
    friend bool operator < (q a,q b){
        return a.k > b.k;
    }
};
int main(){
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i<= n ;i++){
        sz[i] = 1;
        p[i] = i;
    }
    vector<edge> a(n-1);
    for(int i = 0 ; i< n-1 ; i++){
        cin >> a[i].a >> a[i].b >> a[i].w;
    }
    vector<q> b(m);
    for(int i = 0 ; i< m ; i++){
        cin >> b[i].k >> b[i].v;
        b[i].i = i;
    }
    int ans[m];
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    for(int i = 0 ;i < m ; i++){
        int k,v,id;
        k = b[i].k , v = b[i].v , id = b[i].i;
        while(a.size() && a.back().w >=k){
            int x,y,w;
            edge u = a.back();
            x = u.a , y = u.b , w  = u.w;
            if(!same(x,y)){
                unite(x,y);
            }
            a.pop_back();
        }
        ans[id] = sz[find(v)]-1;

    }
    for(int i = 0 ; i< m ; i++) cout << ans[i]<< endl;
}