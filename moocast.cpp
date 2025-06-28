#include <bits/stdc++.h>
using namespace std;

struct edge{
    int x,y,p;
};
double calc(edge a,edge b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
int n;
bool vis[1001];
double d[1001][1001];
int cnt[1001];
vector<edge> arr;
int x;
void dfs(int u){
    cnt[x]++;
    vis[u] = true;
    for(int v = 0 ; v < n; v++){
        if(!vis[v] && arr[u].p >= d[u][v]) dfs(v);
    }
    return;
}
int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    cin >> n;
    for(int i = 0 ;i <n ; i++){
        int a,b,p;
        cin >> a >> b >> p;
        arr.push_back({a,b,p*p});
    }
    for(int i =0 ;i <n ; i++){
        for(int j = i+1 ; j < n ; j++){
            d[i][j] = calc(arr[i] , arr[j]);
            d[j][i] = d[i][j];
        }
    }
    for(int i = 0 ; i< n ;i++) d[i][i] = 0;
    for(int  i = 0 ; i< n ;i++){
        memset(vis,0,sizeof(vis));
        x = i;
        dfs(i);
    }
    int mx = 0;
    for(int i = 0 ; i < n ; i++) mx = max(mx,cnt[i]);
    cout << mx << endl;
}