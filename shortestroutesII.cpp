#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 510;
ll adj[maxn][maxn];
const ll INF =1e18;
ll d[maxn][maxn];
 
int main(){
    memset(adj,0x3f,sizeof(adj));
    int n,m,q;
    cin >> n >> m >> q;
    for(int i =0 ; i< m; i++){
        int a,b;
        ll w;
        cin >> a >> b >> w;
        adj[a][b] = min(w,adj[a][b]);
        adj[b][a] = min(w,adj[b][a]);
    }
    for(int i =1; i<= n; i ++){
        for(int j =1; j <= n ; j++){
            if(i == j) d[i][j] = 0;
            else if(adj[i][j]) d[i][j] = adj[i][j];
            else d[i][j] = INF;
        }
    }
    for(int k = 1; k <= n ; k++){
        for(int i =1; i<= n ; i++){
            for(int j =1; j <= n ; j++){
                d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
            }
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        if(d[a][b] >= INF) cout << -1 << endl;
        else cout <<d[a][b]<< endl;
    }
}
