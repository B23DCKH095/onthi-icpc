#include <bits/stdc++.h>
using namespace std;

int g[1001][1001];
bool vis[1001][1001];
int c[1001][1001];
int n;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
map<pair<pair<int,int>,pair<int,int>> ,bool > mp;
int col = 0;
bool check(int x,int y){
    return (x >= 1 && x <= n && y >= 1 && y <= n && !vis[x][y]);
}
void dfs(int x,int y){
    vis[x][y] = true;
    c[x][y] = col;
    for(int k = 0 ;k < 4; k++){
        int xx = x + dx[k];
        int yy = y + dy[k];
        if(check(xx,yy) && !mp[{{x,y},{xx,yy}}]) dfs(xx,yy);
    }
}
int main(){
    freopen("countcross.in","r",stdin);
    freopen("countcross.out","w",stdout);
    int r,m;
    cin >> n >> r >> m;
    for(int i = 0; i < r ;i++){
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        mp[{{a,b},{x,y}}] = true;
        mp[{{x,y},{a,b}}] = true;
    }
    vector<pair<int,int>> cows;
    for(int i = 0 ; i < m ;i++){
        int a,b;
        cin >> a >> b;
        cows.push_back({a,b});
    }
    // cout << 1 << endl;
    int cnt = 0;
    // for(int i =1; i <= n ;i++){
    //     for(int j =1 ;j <= n ; j++) cout << c[i][j]<<" ";
    //     cout << endl;
    // }
    for(int i = 0 ;i < m ; i++){
        pair<int,int> u = cows[i];
        memset(vis,0,sizeof(vis));
        dfs(u.first,u.second);
        for(int j = 0 ; j< m; j++){
            pair<int,int> v = cows[j];
            if(!vis[v.first][v.second]) ++ cnt;
        }
    }
    cout << cnt/2 << endl;
}