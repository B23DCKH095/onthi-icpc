#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int c[maxn][maxn];
int sz[maxn],p[maxn];

int find(int x){
    while(x != p[x]) x=  p[x];
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
        return a.w > b.w;
    }
};
int main(){
    freopen("superbull.in","r",stdin);
    freopen("superbull.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1 ; i<= n ;i++){
        sz[i] = 1;
        p[i] = i;
    }
    int a[n];
    for(int i = 0 ;i < n; i++) cin >> a[i];
    vector<edge> e;
    for(int i = 0 ; i< n ;i++){
        for(int j =0; j < n ;j++){
            if(i==j) continue;
            c[i][j] = a[i]^a[j];
            e.push_back({i,j,c[i][j]});
        }
    }
    long long mst = 0;
    stable_sort(e.begin() ,e.end());
    for(int i = 0 ;i < e.size() ; i++){
        int aa ,bb ,ww;
        aa = e[i].a , bb = e[i].b , ww = e[i].w;
        aa = find(aa);
        bb = find(bb);
        if(!same(aa,bb)){
            mst += ww;
            unite(aa,bb);
        }
    }
    cout << mst << endl;
}