#include <bits/stdc++.h>

using namespace std;

#define SPEED        ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define eb           emplace_back
#define fi           first
#define se           second
#define mp           make_pair
#define all(x)       (x).begin(), (x).end()
#define lwb          lower_bound
#define upb          upper_bound

typedef long long            ll;
typedef pair<ll, ll>         pll;
typedef pair<int, int>       pii;

template<class T1, class T2> bool maximize(T1 &a, T2 b){return a < b ? a = b, true : false;}
const int N = 1e5 + 3, oo = 1e9;
const ll inf = 1e18;
int n, step[N], dir[N];
pii dxy[200];
ll curx, cury, res;
vector<ll> compressx, compressy;
vector< pair<ll, pll> > vertical_seg, horizontal_seg;
struct Segment{
    ll xa, ya, xb, yb;
    Segment(ll _xa = 0, ll _ya = 0, ll _xb = 0, ll _yb = 0){
        xa = _xa, ya = _ya, xb = _xb, yb = _yb;
    }
};
struct FenwickTree{
    int bit[N * 3], sz;
    void init(int n){
        sz = n;
        fill(bit, bit + 1 + n, 0);
    }
    void update(int i, int v){
        for(; i <= sz; i += i & -i) bit[i] += v;
    }
    int get_sum(int l, int r){
        int res = 0;
        for(; r > 0; r -= r & -r) res += bit[r];
        for(--l; l > 0; l -= l & -l) res -= bit[l];
        return res;
    }
} FT;
vector<Segment> seg;
struct Event{
    int x, y, id;
    Event(int _x = 0, int _y = 0, int _id = -1){
        x = _x, y = _y, id = _id;
    }
    bool operator < (const Event &oth){
        if(x != oth.x) return x < oth.x;
        return (0 <= id && id < oo && 0 <= oth.id && oth.id < oo) ? seg[id].ya < seg[oth.id].ya : id < oth.id;
    }
};
bool have_isect(int last_i){
    vector<Event> event;
    for(int i = 0; i <= last_i; ++i){
        if(seg[i].xa == seg[i].xb){
            event.eb(seg[i].xa, seg[i].ya, i);
        }
        else{
            event.eb(seg[i].xa, seg[i].ya, -1);
            event.eb(seg[i].xb, seg[i].yb, oo);
        }
    }
    sort(all(event));
    FT.init((int)compressy.size());
    for(int i = 0; i < event.size(); ++i){
        int id = event[i].id;
        if(id == -1) FT.update(event[i].y, 1);
        else if(id == oo) FT.update(event[i].y, -1);
        else if(FT.get_sum(seg[id].ya, seg[id].yb) > 0) return true;
    }
    event.eb(-1, -1, -1);
    for(int i = 0; i < event.size(); ++i){
        int id = event[i].id;
        if(id == -1 || id == oo) continue;
        int j = i, max_yb = -oo;
        while(event[j].x == event[i].x && event[j].id < oo){
            if(event[j].y <= max_yb) return true;
            maximize(max_yb, seg[event[j].id].yb); ++j;
        }
        i = j - 1;
    }
    return false;
}
bool ok(ll x, ll y){
    int i;
    i = upb(all(horizontal_seg), mp(y, mp(x, inf))) - horizontal_seg.begin();
    if(i != 0){
        --i;
        if(horizontal_seg[i].fi == y && horizontal_seg[i].se.fi <= x && x <= horizontal_seg[i].se.se) return false;
    }
    i = upb(all(vertical_seg), mp(x, mp(y, inf))) - vertical_seg.begin();
    if(i != 0){
        --i;
        if(vertical_seg[i].fi == x && vertical_seg[i].se.fi <= y && y <= vertical_seg[i].se.se) return false;
    }
    return true;
}
void prepare(){
    dxy['R'] = {1, 0}; dxy['L'] = {-1, 0};
    dxy['U'] = {0, 1}; dxy['D'] = {0, -1};
    compressx.eb(0); compressy.eb(0); seg.eb(0, 0, 0, 0);
}
int main(){
    SPEED;
    cin >> n; prepare();
    for(int i = 0; i < n; ++i){
        char dir; ll step; cin >> dir >> step;
        ::dir[i] = dir; ::step[i] = step;

        ll xa = curx + dxy[dir].fi, xb = curx + dxy[dir].fi * step;
        ll ya = cury + dxy[dir].se, yb = cury + dxy[dir].se * step;

        seg.eb(xa, ya, xb, yb); curx = xb, cury = yb;
        compressx.eb(xa); compressx.eb(xb); compressy.eb(ya); compressy.eb(yb);
    }
    sort(all(compressx)); compressx.erase(unique(all(compressx)), compressx.end());
    sort(all(compressy)); compressy.erase(unique(all(compressy)), compressy.end());

    for(auto &elem : seg){
        elem.xa = lwb(all(compressx), elem.xa) - compressx.begin() + 1;
        elem.xb = lwb(all(compressx), elem.xb) - compressx.begin() + 1;

        elem.ya = lwb(all(compressy), elem.ya) - compressy.begin() + 1;
        elem.yb = lwb(all(compressy), elem.yb) - compressy.begin() + 1;

        if(elem.xa > elem.xb) swap(elem.xa, elem.xb);
        if(elem.ya > elem.yb) swap(elem.ya, elem.yb);
    }
    int l = 0, r = seg.size() - 1, good_idx = n - 1;

    while(l <= r){
        int mid = l + r >> 1;
        if(!have_isect(mid)){
            good_idx = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    curx = 0, cury = 0;
    for(int i = 0; i < good_idx; ++i){
        res += step[i];
        ll nxtx = curx + dxy[dir[i]].fi * step[i];
        ll nxty = cury + dxy[dir[i]].se * step[i];

        if(dir[i] == 'U' || dir[i] == 'D') vertical_seg.eb(curx, mp(min(nxty, cury), max(nxty, cury)));
        else horizontal_seg.eb(cury, mp(min(curx, nxtx), max(curx, nxtx)));

        curx = nxtx, cury = nxty;
    }
    sort(all(vertical_seg)); sort(all(horizontal_seg));
    if(good_idx <= n - 1){
        ll dx = dxy[dir[good_idx]].fi;
        ll dy = dxy[dir[good_idx]].se;
        if(mp(curx + dx, cury + dy) != mp(curx - dxy[dir[good_idx - 1]].fi, cury - dxy[dir[good_idx - 1]].se)){
            do{
                curx += dx;
                cury += dy;
                ++res;
            } while(ok(curx, cury));
        }
    }
    cout << res;
    return 0;
}