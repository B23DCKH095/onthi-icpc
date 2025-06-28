#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int n,m;
char g[1001][1001];
bool bad[1001][1001],good[1001][1001];
bool check(int x,int y){
    return (x >= 1 && x <= n && y >= 1 && y <= m );
}
// struct edge{
//     int x;
//     int y;
//     char c;
// };
// queue<edge> q;
// bool bfs(int x,int y){  
//     while()
// }
void print(){
    for(int i =1; i <= n ;i++){
        for(int j = 1; j <= m ;j ++) cout << g[i][j] <<' ';
        cout << endl;
    }
}
void solve(){
    cin >> n >>m;
    vector<pair<int,int>> e;
    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= n ;j++){
            cin >> g[i][j];
        }
    }
    
    for(pair<int,int> u : e){
        int x = u.first;
        int y = u.second;
        g[x][y] = '#';
        print();
        g[x][y] = '.';
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}