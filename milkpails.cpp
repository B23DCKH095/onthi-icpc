#include <bits/stdc++.h>
using namespace std;

struct state{
    int a,b,k;
    friend bool operator < (state a, state b){
        if(a.a == b.a){
            if(a.b == b.b) return a.k < b.k;
            return a.b < b.b;
        };
        return a.a < b.a;
    }
};
map<state,bool> vis;

int main(){
    freopen("pails.in" , "r",stdin);
    freopen("pails.out","w",stdout);
    int ans = 1e9;
    int n,m,kk,v;
    cin >> n >> m >> kk >> v;
    if(n > m) swap(n,m);
    queue<state> q;
    q.push({0,0,0});
    vis[{0,0,0}] = true;
    while(!q.empty()){
        state u = q.front();
        int a = u.a;
        int b = u.b;
        int k = u.k;
        q.pop();
        ans = min(ans,abs ( a + b - v));
        if(k == kk) continue;
        //1
        if(!vis[{a,m,k+1}]){
            vis[{a,m,k+1}] = true;
            q.push({a,m,k+1});
        }
        if(!vis[{n,b,k+1}]){
            vis[{n,b,k+1}] = true;
            q.push({n,b,k+1});
        }
        //2
        if(!vis[{a,0,k+1}]){
            vis[{a,0,k+1}] = true;
            q.push({a,0,k+1});
        }
        if(!vis[{0,b,k+1}]){
            vis[{0,b,k+1}] = true;
            q.push({0,b,k+1});
        }
        //3
        int lima = n - a;
        int limb = m - b;
        state x = {a + min(lima,b) , b - min(lima,b) , k+1};
        state y = {a - min(limb,a) , b + min(limb,a) , k+1};
        if(!vis[x]){
            vis[x] = true;
            q.push(x);
        }
        if(!vis[y]){
            vis[y] = true;
            q.push(y);
        }
    }
    cout << ans << endl;
}
//fixing