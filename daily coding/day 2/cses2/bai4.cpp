#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define nen(x) sort(x.begin(), x.end());x.erase(unique(x.begin(), x.end()), x.end());
struct Event {
    int x, y1, y2, type;
    bool operator<(const Event& e) const {
        return x < e.x;
    }
};

struct Node {
    int cnt, len;
};

const int MAX_Y = 2e6 + 5;

class SegmentTree {
    vector<Node> tree;
    vector<int> y_coords;
    
    void update_range(int node, int l, int r, int y1, int y2, int val) {
        if (y_coords[r] <= y1 || y_coords[l] >= y2) return;
        if (y1 <= y_coords[l] && y_coords[r] <= y2) {
            tree[node].cnt += val;
        } else {
            int mid = (l + r) / 2;
            update_range(2*node, l, mid, y1, y2, val);
            update_range(2*node+1, mid, r, y1, y2, val);
        }
        
        if (tree[node].cnt > 0) {
            tree[node].len = y_coords[r] - y_coords[l];
        } else {
            tree[node].len = (l + 1 == r) ? 0 : tree[2*node].len + tree[2*node+1].len;
        }
    }

public:
    SegmentTree(vector<int>& y) : y_coords(y) {
        int n = y_coords.size() - 1;
        tree.resize(4 * n);
    }
    
    void add(int y1, int y2) {
        update_range(1, 0, y_coords.size()-2, y1, y2, 1);
    }
    
    void remove(int y1, int y2) {
        update_range(1, 0, y_coords.size()-2, y1, y2, -1);
    }
    
    int get_length() {
        return tree[1].len;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Event> events;
    vector<int> y_coords;
    
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
        y_coords.push_back(y1);
        y_coords.push_back(y2);
    }
    
    // Nén tọa độ y
    nen(y_coords);
    
    // Sắp xếp sự kiện theo x
    sort(events.begin(), events.end());
    
    SegmentTree st(y_coords);
    ll total_area = 0;
    int prev_x = events[0].x;
    
    for (const Event& e : events) {
        int dx = e.x - prev_x;
        if (dx > 0) {
            total_area += (ll)dx * st.get_length();
        }
        
        if (e.type == 1) {
            st.add(e.y1, e.y2);
        } else {
            st.remove(e.y1, e.y2);
        }
        
        prev_x = e.x;
    }
    
    cout << total_area << '\n';
    return 0;
}