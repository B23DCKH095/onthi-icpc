#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn =1e5 + 10;
bool vis[maxn];
vector<pair<int,int>> adj[maxn];
ll d[maxn];

struct state{
    ll w;
    int a;
    bool used;
    friend bool operator < (state a,state b){
        return a.w > b.w;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    for(int i =0 ; i < m;i++){
        int a,b,w;
        cin  >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    for(int i =1 ; i<= n; i++) d[i] = 1e18;
    d[1] = 0;
    priority_queue<state> q;
    q.push({0,1,false});
    while(!q.empty()){
        state u = q.top();
        q.pop();
        int a = u.a;
        if(vis[a]) continue;
        vis[a] = true;
        for(pair<int,int> v :adj[a]){
            int b = v.first;
            int w = v.second;
            if(d[b] > d[a] + w){
                d[b] = d[a] + w;
                q.push({d[b],b,u.used});
            }
            if(u.used) continue;
            w/=2;
            if(d[b] > d[a]+w){
                d[b] = d[a]+w;
                q.push({d[b],b,true});
            }
        }
    }
    cout << d[n]<< endl;
}