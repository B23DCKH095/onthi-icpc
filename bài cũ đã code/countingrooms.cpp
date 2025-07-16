#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};

int a[1005][1005];
bool vis[1005][1005];

int n,m;

bool check(int x,int y){
    return (x >=1 && x <=n && y >= 1 && y <= m && a[x][y] && !vis[x][y]);
}
void dfs(int x,int y){
    vis[x][y] = true;
    for(int k = 0 ;k < 4; k ++){
        int xx = x + dx[k];
        int yy = y + dy[k];
        if(check(xx,yy))dfs(xx,yy);
    }
}
int main(){
    cin >> n >>m;
    for(int i = 1 ; i<= n ; i++){
        for(int j = 1; j <=m ; j++){
            char c;
            cin >> c;
            a[i][j] = (c == '.');
        }
    }

    int cnt = 0;
    for(int i = 1 ; i<= n; i++){
        for(int j = 1; j <= m ;j++){
            if(a[i][j] && !vis[i][j]){
                ++ cnt;
                dfs(i,j);
            }
        }
    }
    cout << cnt << endl;
}