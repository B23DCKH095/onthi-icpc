#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn =1e5 + 10;
vector<pair<int,int>> adj[maxn];
bool vis[maxn];
ll d[maxn];
int main(){
    int n,m;
    cin >> n >>m;
    for(int i =0 ; i <m ; i++){
        int a,b,w;
        cin >> a >> b>> w;
        adj[a].push_back({b,w});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push({0,1});
    for(int i =1; i<= n; i++) d[i] = 1e18;
    d[1] = 0;
    while(!q.empty()){
        pair<int,int> u = q.top();
        q.pop();
        int a = u.second;
        if(vis[a]) continue;
        vis[a] = true;
        for(pair<int,int> v : adj[a]){
            int b = v.first;
            int w = v.second;
            if(d[b] > d[a] + w){
                d[b] = d[a] + w;
                q.push({d[b],b});
            }
        }
    }
    for(int i =1; i <= n ;i++) cout << d[i]<<" ";
}