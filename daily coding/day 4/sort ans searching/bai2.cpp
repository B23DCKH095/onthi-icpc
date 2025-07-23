#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of -inf
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
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<pii> a(n);
    vi nen;
    for (auto &[l, r] : a) {
        cin >> l >> r;
        nen.push_back(l);
        nen.push_back(r);
    }

    // Coordinate Compression
    sort(all(nen));
    nen.erase(unique(all(nen)), nen.end());
    map<int, int> mp;
    rep(i, 0, sz(nen)) mp[nen[i]] = i;

    // Update intervals with compressed indices
    for (auto &[l, r] : a) {
        l = mp[l];
        r = mp[r];
    }

    // Initialize segment tree with size = number of unique points
    int m = sz(nen);
    vi v(m, 0);
    Node* tree = new Node(v, 0, m);

    // Add intervals to the tree
    for (auto [l, r] : a) {
        tree->add(l, r+1, 1); // [l, r] inclusive
    }

    // Query max overlap for each interval
    for (auto [l, r] : a) {
        cout << tree->query(l, r + 1) << " ";
    }
    cout << "\n";
    return 0;
}