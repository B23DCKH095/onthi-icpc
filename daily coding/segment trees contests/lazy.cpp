#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> seg, lazy_set, lazy_add;
int n;

void build(int _n) {
    n = _n;
    seg.assign(4*n, -INF);
    lazy_set.assign(4*n, INF);
    lazy_add.assign(4*n, 0);
}

void push(int node, int l, int r) {
    if (lazy_set[node] != INF) {
        seg[node] = lazy_set[node];
        if (l != r) {
            lazy_set[2*node] = lazy_set[2*node+1] = lazy_set[node];
            lazy_add[2*node] = lazy_add[2*node+1] = 0;
        }
        lazy_set[node] = INF;
    }
    else if (lazy_add[node]) {
        seg[node] += lazy_add[node];
        if (l != r) {
            if (lazy_set[2*node] != INF) lazy_set[2*node] += lazy_add[node];
            else lazy_add[2*node] += lazy_add[node];
            if (lazy_set[2*node+1] != INF) lazy_set[2*node+1] += lazy_add[node];
            else lazy_add[2*node+1] += lazy_add[node];
        }
        lazy_add[node] = 0;
    }
}

void update_set(int node, int l, int r, int a, int b, int val) {
    push(node, l, r);
    if (r < a || b < l) return;
    if (a <= l && r <= b) {
        lazy_set[node] = val;
        lazy_add[node] = 0;
        push(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update_set(2*node, l, mid, a, b, val);
    update_set(2*node+1, mid+1, r, a, b, val);
    seg[node] = max(seg[2*node], seg[2*node+1]);
}

void update_add(int node, int l, int r, int a, int b, int val) {
    push(node, l, r);
    if (r < a || b < l) return;
    if (a <= l && r <= b) {
        lazy_add[node] += val;
        push(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update_add(2*node, l, mid, a, b, val);
    update_add(2*node+1, mid+1, r, a, b, val);
    seg[node] = max(seg[2*node], seg[2*node+1]);
}

int query_max(int node, int l, int r, int a, int b) {
    push(node, l, r);
    if (r < a || b < l) return -INF;
    if (a <= l && r <= b) return seg[node];
    int mid = (l + r) / 2;
    return max(query_max(2*node, l, mid, a, b),
              query_max(2*node+1, mid+1, r, a, b));
}