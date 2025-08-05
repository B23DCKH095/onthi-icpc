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
 * Date: 2015-09-12
 * License: CC0
 * Source: me
 * Description: When you need to dynamically allocate many objects and don't care about freeing them.
 * "new X" otherwise has an overhead of something like 0.05us + 16 bytes per allocation.
 * Status: tested
 */

// Either globally or in a single class:
static char buf[450 << 20];
void* operator new(size_t s) {
      static size_t i = sizeof buf;
      assert(s < i);
      return (void*)&buf[i -= s];
}
void operator delete(void*) {}

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};
 
template <bool VALS_EDGES> struct HLD {
    int N, tim = 0;
    vector<vi> adj;
    vi par, siz, rt, pos;
    Node *tree;
    HLD(vector<vi> adj_)
        : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1),
          rt(N),pos(N),tree(new Node(0, N)){ dfsSz(0); dfsHld(0); }
    void dfsSz(int v) {
        for (int& u : adj[v]) {
            adj[u].erase(find(all(adj[u]), v));
            par[u] = v;
            dfsSz(u);
            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
        }
    }
    void dfsHld(int v) {
        pos[v] = tim++;
        for (int u : adj[v]) {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
    }
    template <class B> void process(int u, int v, B op) {
        for (;; v = par[rt[v]]) {
            if (pos[u] > pos[v]) swap(u, v);
            if (rt[u] == rt[v]) break;
            op(pos[rt[v]], pos[v] + 1);
        }
        op(pos[u] + VALS_EDGES, pos[v] + 1);
    }
    void modifyPath(int u, int v, int val) {
        process(u, v, [&](int l, int r) { tree->set(l, r, val); });
    }
    void modifyVertex(int u, int val) {
        tree->set(pos[u], pos[u]+1, val);
    }
    int queryPath(int u, int v) {
        int res = -1e9;
        process(u, v, [&](int l, int r) {
            res = max(res, tree->query(l, r));
        });
        return res;
    }
    int queryVertex(int u) {
        return tree->query(pos[u], pos[u]+1);
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n, q;
    cin >> n >> q;
    vi val(n);
    for(int i = 0; i < n; i++) cin >> val[i];
    
    vector<vi> edges(n);
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    HLD<false> hld(edges);
    for(int i = 0; i < n; i++) {
        hld.modifyVertex(i, val[i]);
    }
    
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int i, v;
            cin >> i >> v;
            i--; // Convert to 0-based
            hld.modifyVertex(i,-val[i]);
            val[i] = v;
            hld.modifyVertex(i,val[i]);
        }
        else {
            int a,b;
            cin >> a >> b;
            --a ,--b;
            cout << hld.queryPath(a, b) << " ";
        }
    }
}
