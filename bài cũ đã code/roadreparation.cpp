#include <bits/stdc++.h>
using namespace std;

const int maxn =1e5 + 10;
int p[maxn],sz[maxn];

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
int main(){
    int n,m;
    cin >> n >> m;
    for(int i =1; i<= n ;i++){
        sz[i] = 1;
        p[i] =i;
    }
    vector<edge> e;
    for(int i = 0 ;i <m ; i++){
        int a,b,w;
        cin >>  a >> b >> w;
        e.push_back({a,b,w});
    }
    stable_sort(e.begin() , e.end());
    long long mst = 0;
    for(int i = 0; i < m; i++){
        int a = e[i].a;
        int b = e[i].b;
        int w = e[i].w;
        a = find(a);
        b = find(b);
        if(!same(a,b)){
            unite(a,b);
            mst += w;
        }
    }
    if(sz[find(1)] != n) cout << "IMPOSSIBLE"<< endl;
    else cout << mst << endl;
}