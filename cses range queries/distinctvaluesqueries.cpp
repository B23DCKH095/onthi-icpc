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
 * Date: 2019-12-28
 * License: CC0
 * Source: https://github.com/hoke-t/tamu-kactl/blob/master/content/data-structures/MoQueries.h
 * Description: Answer interval or tree path queries by finding an approximate TSP through the queries,
 * and moving from one query to the next by adding/removing points at the ends.
 * If values are on tree edges, change \texttt{step} to add/remove the edge $(a, c)$ and remove the initial \texttt{add} call (but keep \texttt{in}).
 * Time: O(N \sqrt Q)
 * Status: stress-tested
 */

const int MAXN = 2e5 + 5;
int a[MAXN], cnt[MAXN], distinct = 0;
 
void add(int ind, int end) {
    if (cnt[a[ind]] == 0) distinct++;
    cnt[a[ind]]++;
}
 
void del(int ind, int end) {
    cnt[a[ind]]--;
    if (cnt[a[ind]] == 0) distinct--;
}
 
int calc() {
    return distinct;
}

vi mo(vector<pii> Q) {
      int L = 0, R = 0, blk = 350; // ~N/sqrt(Q)
      vi s(sz(Q)), res = s;
#define K(x) pii(x.first/blk, x.second ^ -(x.first/blk & 1))
      iota(all(s), 0);
      sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
      for (int qi : s) {
            pii q = Q[qi];
            while (L > q.first) add(--L, 0);
            while (R < q.second) add(R++, 1);
            while (L < q.first) del(L++, 0);
            while (R > q.second) del(--R, 1);
            res[qi] = calc();
      }
      return res;
}

vi moTree(vector<array<int, 2>> Q, vector<vi>& ed, int root=0){
      int N = sz(ed), pos[2] = {}, blk = 350; // ~N/sqrt(Q)
      vi s(sz(Q)), res = s, I(N), L(N), R(N), in(N), par(N);
      add(0, 0), in[0] = 1;
      auto dfs = [&](int x, int p, int dep, auto& f) -> void {
            par[x] = p;
            L[x] = N;
            if (dep) I[x] = N++;
            for (int y : ed[x]) if (y != p) f(y, x, !dep, f);
            if (!dep) I[x] = N++;
            R[x] = N;
      };
      dfs(root, -1, 0, dfs);
#define K(x) pii(I[x[0]] / blk, I[x[1]] ^ -(I[x[0]] / blk & 1))
      iota(all(s), 0);
      sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
      for (int qi : s) rep(end,0,2) {
            int &a = pos[end], b = Q[qi][end], i = 0;
#define step(c) { if (in[c]) { del(a, end); in[a] = 0; } \
                  else { add(c, end); in[c] = 1; } a = c; }
            while (!(L[b] <= L[a] && R[a] <= R[b]))
                  I[i++] = b, b = par[b];
            while (a != b) step(par[a]);
            while (i--) step(I[i]);
            if (end) res[qi] = calc();
      }
      return res;
}
vector<int> coordinate_compression(vector<int>& arr) {
    vector<int> sorted_arr = arr;
    
    // Bước 1: Sắp xếp và loại bỏ trùng lặp
    sort(sorted_arr.begin(), sorted_arr.end());
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
    
    // Bước 2: Ánh xạ mỗi giá trị về chỉ số của nó
    vector<int> compressed;
    for (int num : arr) {
        int idx = lower_bound(sorted_arr.begin(), sorted_arr.end(), num) - sorted_arr.begin();
        compressed.push_back(idx);
    }
    
    return compressed;
}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     int n,q;
     cin >> n >> q;
     vector<int> v(n);
     for(int i = 0; i <n ; i++) cin >> v[i];
     vi b = coordinate_compression(v);
     for(int i = 0 ; i<n ; i++) a[i] = b[i];
     vector<pii> queries(q);
     for(int i =0 ;i <q ; i++){
        cin >> queries[i].first >> queries[i].second;
        -- queries[i].first;
     }
     vi ans = mo(queries);
     for(int x : ans) cout << x << endl;
}