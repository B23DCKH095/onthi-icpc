#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1001][1001];
bool vis[1001][1001];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
vector<pair<int,int>> point;
bool check(int x,int y){
    return (x >=1 && x<= n && y >=1 && y <= m && !vis[x][y]);
}
bool ok(int d){
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>> q;
    pair<int,int> u = point.front();
    q.push({u.first,u.second});
    vis[u.first][u.second] = true;
    while(!q.empty()){
        u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;
        for(int k = 0 ;k <4 ; k++){
            int xx = x + dx[k];
            int yy = y + dy[k];
            if(check(xx,yy) && abs(a[xx][yy] - a[x][y]) <= d){
                vis[xx][yy] = true;
                q.push({xx,yy});
            }
        }
    }
    for(pair<int,int> x : point){
        if(!vis[x.first][x.second]) return false;
    }
    return true;
}
int bs(){
    int l = 0, r = INT32_MAX;
    while(l < r){
        int m = l + (r-l)/2;
        if(ok(m)) r= m;
        else l = m+1;
    }
    return l;
}
int main(){
    freopen("ccski.in","r",stdin);
    freopen("ccski.out","w",stdout);
    cin >> n >> m;
    for(int i= 1; i<= n ;i++){
        for(int j = 1;j <=m ; j++) cin >>a[i][j];
    }
    for(int i =1; i<= n;i ++){
        for(int j = 1; j<= m; j++){
            int x;
            cin >> x;
            if(x) point.push_back({i,j});
        }
    }
    cout << bs()<< endl;
}