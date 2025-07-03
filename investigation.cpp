#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn =1e5 + 10;
vector<pair<int,int>> adj[maxn];
bool vis[maxn];
ll d[maxn],num[maxn],minf[maxn],maxf[maxn];
const int mod = 1e9 + 7;

int main(){
    int n,m;
    cin >> n >>m;
    for(int i = 0 ;i < m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    for(int i =1; i<= n ;i++) d[i] = 1e18;
    priority_queue<pair<ll,int> ,vector<pair<ll,int>> , greater<pair<ll,int>>> q;
    d[1] = 0;
    num[1] = 1;
    q.push({0,1});
    while(!q.empty()){
        pair<ll,int> u = q.top();
        q.pop();
        if(vis[u.second]) continue;
        vis[u.second] = true;
        for(pair<int,int> v : adj[u.second]){
            ll w = u.first + v.second;
            if(w == d[v.first]){
                num[v.first] = (num[v.first]+num[u.second])%mod;
                minf[v.first] = min(minf[v.first] , minf[u.second]+1);
                maxf[v.first] = max(maxf[v.first],maxf[u.second]+1);
            } else if(w < d[v.first]){
                num[v.first] = num[u.second];
                minf[v.first] = minf[u.second]+1;
                maxf[v.first] = maxf[u.second]+1;
                d[v.first] = w;
                q.push({w,v.first});
            }
        }
    }
    cout << d[n]<<' '<< num[n] << " "<< minf[n]<<" "<< maxf[n]<< endl;
}