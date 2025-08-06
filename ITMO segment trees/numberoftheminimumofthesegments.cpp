#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pii combine(pii a, pii b)
{
    if (a.first < b.first)
        return a;
    if (b.first < a.first)
        return b;
    return {a.first, a.second + b.second};
}
const int maxn = 1e5 + 10;
int n;
pii t[4 * maxn];
void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = {a[tl], 1};
    }
    else
    {
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }
}
pii query(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return {INT_MAX, 0};
    if (tl == l && tr == r)
        return t[v];
    int tm = tl + (tr - tl) / 2;
    return combine(query(2 * v, tl, tm, l, min(r, tm)), query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
void update(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr)
    {
        t[v] = {val, 1};
    }
    else
    {
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = combine(t[2 * v], t[2 * v + 1]);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(a, 1, 0, n - 1);
    while (q--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1)
            update(1, 0, n - 1, u, v);
        else
        {
            pii ret = query(1, 0, n - 1, u, v - 1);
            cout << ret.first << " " << ret.second << endl;
        }
    }
}