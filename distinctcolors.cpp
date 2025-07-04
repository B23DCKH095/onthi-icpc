#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int timedfs;
const int maxn =2e5 + 10;
vector<int> adj[maxn];
ll d[maxn],id[maxn],val[maxn],tree[maxn];
int n;
int st[maxn],en[maxn],col[maxn],same[maxn];
void dfs(int u,int p){
    st[u] = ++ timedfs;
    int cnt = col[u];
    for(int v: adj[u]){
        if(v==p) continue;
        if(cnt | col[v] != cnt){
            ++ same[u];
            cnt |= col[v];
        }
        cout << cnt << endl;
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
    cin >> n;
    for(int i =1; i<= n ;i++) cin >> col[i];
    for(int i = 0 ; i< n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
}