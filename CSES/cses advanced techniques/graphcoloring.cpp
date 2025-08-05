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
 * Date: 2020-10-12
 * License: CC0
 * Source: https://en.wikipedia.org/wiki/Misra_%26_Gries_edge_coloring_algorithm
 * https://codeforces.com/blog/entry/75431 for the note about bipartite graphs.
 * Description: Given a simple, undirected graph with max degree D$, computes a
 * $(D + 1)$-coloring of the edges such that no neighboring edges share a color.
 * (D$-coloring is NP-hard, but can be done for bipartite graphs by repeated matchings of
 * max-degree nodes.)
 * Time: O(NM)
 * Status: stress-tested, tested on kattis:gamescheduling
 */
#pragma once

vi edgeColoring(int N, vector<pii> eds) {
      vi cc(N + 1), ret(sz(eds)), fan(N), free(N), loc;
      for (pii e : eds) ++cc[e.first], ++cc[e.second];
      int u, v, ncols = *max_element(all(cc)) + 1;
      vector<vi> adj(N, vi(ncols, -1));
      for (pii e : eds) {
            tie(u, v) = e;
            fan[0] = v;
            loc.assign(ncols, 0);
            int at = u, end = u, d, c = free[u], ind = 0, i = 0;
            while (d = free[v], !loc[d] && (v = adj[u][d]) != -1)
                  loc[d] = ++ind, cc[ind] = d, fan[ind] = v;
            cc[loc[d]] = c;
            for (int cd = d; at != -1; cd ^= c ^ d, at = adj[at][cd])
                  swap(adj[at][cd], adj[end = at][cd ^ c ^ d]);
            while (adj[fan[i]][d] != -1) {
                  int left = fan[i], right = fan[++i], e = cc[i];
                  adj[u][e] = left;
                  adj[left][e] = u;
                  adj[right][e] = -1;
                  free[right] = e;
            }
            adj[u][d] = fan[i];
            adj[fan[i]][d] = u;
            for (int y : {fan[0], u, end})
                  for (int& z = free[y] = 0; adj[y][z] != -1; z++);
      }
      rep(i,0,sz(eds))
            for (tie(u, v) = eds[i]; adj[u][ret[i]] != v;) ++ret[i];
      return ret;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m;
     cin >> n >> m;
     vector<pii> edges;
     for(int i= 0; i <m ; i++){
        pii x;
        cin >> x.first >> x.second;
        --x.first ,--x.second;
        edges.push_back(x);
     }
     vi ans = edgeColoring(n,edges);
     set<int> se;
     for(int x : ans)se.insert(x+1);
     cout << se.size() << endl;
     for(int x : ans) cout << x+1 <<" ";
}