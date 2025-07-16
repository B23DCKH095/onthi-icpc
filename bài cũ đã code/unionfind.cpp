#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
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
    if(same(a,b)) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    p[b] = a;
}
int main(){
    int n,q;
    cin >> n >> q;
    for(int i =1 ;i <= n; i++){
        p[i] = i;
        sz[i] = 1;
    }
    while(q--){
        int t,a,b;
        cin >> t >> a >> b;
        if(t==1) cout << same(a,b)<< endl;
        else unite(a,b);
    }
}