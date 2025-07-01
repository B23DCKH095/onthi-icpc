#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int p[maxn], sz[maxn];

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
    int n,m;
    cin >> n >>m;
    for(int i = 1 ;i <= n; i++){
        sz[i] = 1;
        p[i] = i;
    }
    int tplt = n;
    int mx = 0;
    for(int i = 0 ;i < m; i++){
        int a,b;
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if(!same(a,b)){
            unite(a,b);
            tplt --;
        }
        mx = max(mx , max(sz[a], sz[b]));
        cout << tplt << " "<< mx << endl; 
    }
}