#include <bits/stdc++.h>
using namespace std;

const int maxn = 4010;
char c[maxn][maxn];
int d[maxn][maxn];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool vis[maxn][maxn];
int n,m;

bool check(int x,int y){
    return (x >= 1 && x <= n && y >= 1 && y <= m && c[x][y] != '.' && !vis[x][y]);
}
void bfs(){
    vis[1][1] = true;
    int ans = 0;
    deque<pair<int,int>> q;
    q.push_front({1,1});
    d[1][1] = 1;
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop_front();
        ans = max(ans,d[u.first][u.second]);
        for(int k = 0 ; k < 4; k++){
            int xx = u.first + dx[k];
            int yy = u.second + dy[k];
            if(check(xx,yy)){
                if(c[u.first][u.second] == c[xx][yy]){
                    vis[xx][yy] = true;
                    d[xx][yy] = d[u.first][u.second];
                    q.push_front({xx,yy});
                }
                else {
                    vis[xx][yy] = true;
                    d[xx][yy] = d[u.first][u.second] + 1;
                    q.push_back({xx,yy});
                }
            }
        }
    }
    cout << ans << endl;
}
int main(){
    cin >> n >> m;
    for(int i =1; i<= n ;i++){
        for(int j = 1 ; j <= m ;j ++) cin >> c[i][j];
    }
    bfs();
}