#include <bits/stdc++.h>
using namespace std;

char g[1010][1010];
bool vis[1010][1010];
pair<int,int> p[1001][1001];
char c[1001][1001];
int n,m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char d[] = {'U','D','L','R'};
int xst,yst,xen,yen;
bool check(int x,int y){
    return (x >=1 && x <= n && y >= 1 && y <= m && g[x][y] != '#' &&!vis[x][y]);
}
void bfs(){
    queue<pair<int,int>> q;
    q.push({xst,yst});
    vis[xst][yst]= true;
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        for(int k = 0 ;k < 4; k++){
            int x = u.first + dx[k];
            int y = u.second + dy[k];
            if(check(x,y)){
                p[x][y] = u;
                c[x][y]  = d[k];
                vis[x][y] = true;
                q.push({x,y});
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i<= n ; i++){
        for(int j = 1; j<= m ;j ++){
            cin >> g[i][j];
            if(g[i][j] == 'A'){
                xst = i;
                yst = j;
            }
            if(g[i][j] == 'B'){
                xen = i;
                yen = j;
            }
        }
    }
    bfs();
    if(!vis[xen][yen]){
        cout <<"NO" << endl;
    }
    else {
        cout << "YES"<< endl;
        string ans;
        pair<int,int> u = {xen,yen};
        while(u.first != xst || u.second != yst){
            ans += c[u.first][u.second];
            u = p[u.first][u.second];
        }
        reverse(ans.begin() ,ans.end());
        cout << ans.size()<< endl;
        cout << ans << endl;
    }
}