#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Simon Lindholm
 * Date: 2019-12-31
 * License: CC0
 * Source: folklore
 * Description: Eulerian undirected/directed path/cycle algorithm.
 * Input should be a vector of (dest, global edge index), where
 * for undirected graphs, forward/backward edges have the same index.
 * Returns a list of nodes in the Eulerian path/cycle with src at both start and end, or
 * empty list if no cycle/path exists.
 * To get edge indices back, add .second to s and ret.
 * Time: O(V + E)
 * Status: stress-tested
 */
#pragma once

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
      int n = sz(gr);
      vi D(n), its(n), eu(nedges), ret, s = {src};
      D[src]++; // to allow Euler paths, not just cycles
      while (!s.empty()) {
            int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
            if (it == end){ ret.push_back(x); s.pop_back(); continue; }
            tie(y, e) = gr[x][it++];
            if (!eu[e]) {
                  D[x]--, D[y]++;
                  eu[e] = 1; s.push_back(y);
            }}
      for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
      return {ret.rbegin(), ret.rend()};
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m;
     cin >> n >> m;
     vector<vector<pii>> gr(n);
     for(int i =0 ;i < m ; i++){
        int x,y;
        cin >> x >> y;
        --x,--y;
        gr[x].push_back({y,i});
     }
     vi ans = eulerWalk(gr,m,0);
     if(sz(ans) ==0 || ans[sz(ans)- 1] != n-1) cout <<"IMPOSSIBLE"<< endl;
     else for(int x : ans) cout << x+1 <<" ";
}