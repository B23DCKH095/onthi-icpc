#include <bits/stdc++.h>
using namespace std;

int n,m;
const int maxn = 1010;
char g[1010][1010];
int pre[1010][1010];
int main(){
    cin >> n >> m;
    for(int i = 0 ; i< n ; i ++){
        for(int j = 0 ; j < n ; j++) {
            cin >> g[i][j];
            if(g[i][j] == '*') pre[i+1][j+1] = 1;
        }
    }
    for(int i =1; i<= n ; i++){
        for(int j = 1 ; j<= n ;j++){
            pre[i][j] += pre[i][j-1]+ pre[i-1][j] - pre[i-1][j-1];
        }
    }
    for(int i = 0 ; i< m ; i++){
        int u,v,x,y;
        cin >> u >> v >> x >> y;
        cout << pre[x][y] - pre[u-1][y] - pre[x][v-1]+ pre[u-1][v-1]<< endl;
    }

}