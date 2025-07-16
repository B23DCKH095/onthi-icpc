#include <bits/stdc++.h>
using namespace std;

bool vis[60][60];
char grid[60][60];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n,m;

bool check(int x,int y){
    return (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && grid[x][y] != '#');
}
void dfs(int x,int y){
    if(grid[x][y] == '#') return;
    vis[x][y] = true;
    for(int k = 0 ;k  < 4; k++){
        int xx = x + dx[k];
        int yy = y + dy[k];
        if(check(xx,yy)) dfs(xx,yy);
    }
}
void solve(){
    cin >> n >> m;
    memset(vis,0,sizeof(vis));
    for(int i = 1; i<= n ;i++){
        for(int j = 1; j<= m ; j++) cin >> grid[i][j];
    }
    for(int i =1; i <= n ;i++){
        for(int j =1; j<= m ;j ++){
            if(grid[i][j] == 'B'){
                for(int k = 0; k < 4 ;k ++){
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if(check(xx,yy)){
                        if(grid[xx][yy] == 'G'){
                            cout <<"No"<< endl;
                            return;
                        }
                        if(grid[xx][yy] == '.') grid[xx][yy] ='#';
                    }
                }
            }
        }
    }
    dfs(n,m);
    for(int i =1; i<= n; i++){
        for(int j = 1; j<= m; j++){
            if(grid[i][j] == 'G' && !vis[i][j]){
                cout <<"No"<< endl;
                return;
            }
        }
    }
    cout <<"Yes"<< endl;
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}