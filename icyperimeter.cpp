#include <bits/stdc++.h>
using namespace std;

char g[1001][1001];
bool vis[1001][1001];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int n;
vector<vector<pair<int,int>>> tplt;
bool check(int x,int y){
    return (x>= 1 && x <= n && y >= 1 && y <= n && g[x][y] == '#' && !vis[x][y]);
}