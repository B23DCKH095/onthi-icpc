#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int timedfs;
const int maxn =2e5 + 10;
vector<int> adj[maxn];
ll d[maxn],id[maxn],val[maxn],tree[maxn];
int n;
int st[maxn],en[maxn];

void dfs(int u,int p){
    st[u] = ++ timedfs;
    for(int v: adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    en[u] = timedfs;
}
ll sum(int k){
    ll s = 0;
    while(k >= 1){
        s += tree[k];
        k-= k&-k;
    }
    return s;
}
void add(int k,int x){
    while(k <= n){
        tree[k] += x;
        k += k&-k;
    }
}
int main(){
    int q;
    cin >> n >> q;
    for(int i = 1 ; i<= n ; i++) cin >> val[i];
    for(int i = 0 ; i < n-1 ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    for(int i = 1; i<= n ; i++) add(st[i],val[i]);
    for(int i = 0 ; i< q; i ++){
        int t;
        cin >> t;
        if(t==1){
            int s,x;
            cin >> s >> x;
            add(st[s],-val[s]);
            val[s] = x;
            add(st[s] ,val[s]);
        }
        else {
            int s;
            cin >> s;
            cout << sum(en[s]) - sum(st[s] -1)<< endl;
        }
    }
}