#include <bits/stdc++.h>
using namespace std;

bool vis[1001][1001];
char g[1001][1001];
char c[1001][1001];
int n,m;
pair<int,int> p[1001][1001];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char d[] = {'D','U','R','L'};

bool check(int x,int y){
    return (x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] != '#' && !vis[x][y]);
}
void bfs(int x,int y){
    vis[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        if(g[u.first][u.second] == 'M') return;
        for(int k = 0 ; k < 4 ; k++){
            int xx = u.first + dx[k];
            int yy = u.second + dy[k];
            if(check(xx,yy)){
                p[xx][yy] = u;
                vis[xx][yy] = true;
                c[xx][yy] = d[k];
                q.push({xx,yy});
            }
        }
    }
}
int main(){
    int xst,yst;
    cin >> n >>m;
    for(int i = 1 ; i<= n; i++){
        for(int j =1; j<= m ; j++){
            cin >> g[i][j];
            if(g[i][j] == 'A'){
                xst = i;
                yst = j;
            }
        }
    }
    int xen,yen;
    for(int i = 1 ; i<= n ;i++){
        for(int j =1; j<= m; j++){
            if((i == 1 || i == n || j == 1 || j == m) && g[i][j] != '#'){
                bfs(i,j);
                if(vis[xst][yst]){
                    cout <<"YES"<< endl;
                    string ans = "";
                    xen = i;
                    yen = j;
                    pair<int,int> u = {xst , yst};
                    while(xen != u.first || yen != u.second){
                        ans += c[u.first][u.second];
                        u = p[u.first][u.second];
                    }
                    cout << ans.size() << endl;
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    cout <<"NO"<< endl;
}