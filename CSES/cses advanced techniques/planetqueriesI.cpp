#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#pragma once

vector<vi> treeJump(vi& P){
      int on = 1, d = 1;
      while(on < sz(P)) on *= 2, d++;
      vector<vi> jmp(d, P);
      rep(i,1,d) rep(j,0,sz(P))
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
      return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps){
      rep(i,0,sz(tbl))
            if(steps&(1<<i)) nod = tbl[i][nod];
      return nod;
}

int lca(vector<vi>& tbl, vi& depth, int a, int b) {
      if (depth[a] < depth[b]) swap(a, b);
      a = jmp(tbl, a, depth[a] - depth[b]);
      if (a == b) return a;
      for (int i = sz(tbl); i--;) {
            int c = tbl[i][a], d = tbl[i][b];
            if (c != d) a = c, b = d;
      }
      return tbl[0][a];
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,m;
     cin >> n >> m;
     vi p(n);
     for(int i =0 ;i <n ; i++){
        int x;
        cin >> x;
        --x;
        p[x] = i;
     }
     vector<vi> jumptable = treeJump(p);
     while(m--){
        int u,k;
        cin >> u >> k;
        --u;
        cout << jmp(jumptable,u,k)+1 << endl;
     }
}