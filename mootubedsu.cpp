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
int main(){
    int n,m;
    cin >
}