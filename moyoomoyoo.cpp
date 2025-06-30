#include <bits/stdc++.h>
using namespace std;

bool vis[1001][1001];
char g[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, cnt;

bool check(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= 10 && !vis[x][y] && g[x][y] != '0');
}

void dem(int x, int y, int col) {
    vis[x][y] = true;
    cnt++;  // Count the current cell
    for(int k = 0; k < 4; k++) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if(check(xx, yy) && col == g[xx][yy]) {
            dem(xx, yy, col);
        }
    }
}

void xoa(int x, int y, int col) {
    vis[x][y] = true;
    g[x][y] = '0';
    for(int k = 0; k < 4; k++) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= 10 && g[xx][yy] == col) {
            xoa(xx, yy, col);
        }
    }
}

void apply() {
    for(int j = 1; j <= 10; j++) {
        int empty = n;  // Points to the next empty position from bottom
        for(int i = n; i >= 1; i--) {
            if(g[i][j] != '0') {
                swap(g[empty][j], g[i][j]);
                empty--;
            }
        }
    }
}

int main() {
    freopen("mooyomooyo.in","r",stdin);
    freopen("mooyomooyo.out","w",stdout);
    int k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 10; j++) {
            cin >> g[i][j];
        }
    }
    
    while(true) {
        vector<pair<int, int>> a;
        memset(vis, false, sizeof(vis));
        
        // Find all regions to remove
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 10; j++) {
                if(!vis[i][j] && g[i][j] != '0') {
                    cnt = 0;
                    dem(i, j, g[i][j]);
                    if(cnt >= k) {
                        a.push_back({i, j});
                    }
                }
            }
        }
        
        if(a.empty()) break;
        
        // Remove the marked regions
        memset(vis, false, sizeof(vis));
        for(auto u : a) {
            if(g[u.first][u.second] != '0') {  // Check if not already removed
                xoa(u.first, u.second, g[u.first][u.second]);
            }
        }
        
        // Apply gravity
        apply();
    }
    
    // Output the final grid
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 10; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
    
    return 0;
}