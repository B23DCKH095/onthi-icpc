#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Source:
 * Description: Simple bipartite matching algorithm. Graph $g$ should be a list
 * of neighbors of the left partition, and $btoa$ should be a vector full of
 * -1's of the same size as the right partition. Returns the size of
 * the matching. $btoa[i]$ will be the match for vertex $i$ on the right side,
 * or $-1$ if it's not matched.
 * Time: O(VE)
 * Usage: vi btoa(m, -1); dfsMatching(g, btoa);
 * Status: works
 */
#pragma once

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
	vi vis;
	rep(i,0,sz(g)) {
		vis.assign(sz(btoa), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return sz(btoa) - (int)count(all(btoa), -1);
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m,k;
     cin >> n >> m >> k;
     vector<vector<int>> g(n);  // Danh sách kề cho bên trái
    vector<int> btoa(m, -1);  // Ánh xạ từ bên phải sang bên trái
    for(int i = 0 ; i< k ; i++){
        int x,y;
        cin >> x >> y;
        --x,--y;
        g[x].push_back(y);
    }
    int matching_size = dfsMatching(g,btoa);
    cout << matching_size<< endl;

// In ra các cặp ghép
    vector<int> atob(n,-1);
    for(int j = 0 ;j < m ; j++){
        if(btoa[j] != -1) atob[btoa[j]] = j;
    }
    for(int i = 0 ; i< n; i++){
        if(atob[i] != -1) cout << i+1 <<" "<< atob[i]+1<< endl;
    }
}