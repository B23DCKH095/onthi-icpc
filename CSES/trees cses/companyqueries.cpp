#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> treeJump(vi& P) {
    int on = 1, d = 1;
    while(on < sz(P)) on *= 2, d++;
    vector<vi> jmp(d, P);
    rep(i,1,d) rep(j,0,sz(P))
        jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps) {
    rep(i,0,sz(tbl))
        if(steps&(1<<i)) nod = tbl[i][nod];
    return nod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    // Mảng cha, P[i] là cha của nút i (0-based)
    vi P(n);
    P[0] = 0; // Gốc có cha là chính nó
    for(int i = 1; i < n; i++) {
        cin >> P[i];
        P[i]--; // Chuyển về 0-based nếu input là 1-based
    }
    
    // Tiền xử lý bảng nhảy
    vector<vi> jump_table = treeJump(P);
    
    // Tính depth cho các nút
    vi depth(n, 0);
    for(int i = 1; i < n; i++)
        depth[i] = depth[P[i]] + 1;
    
    // Xử lý truy vấn
    while(q--) {
        int node, k;
        cin >> node >> k;
        node--; // Chuyển về 0-based
        
        // Kiểm tra nếu k quá lớn
        if (k > depth[node]) {
            cout << -1 << endl;
            continue;
        }
        
        // Lấy tổ tiên thứ k
        int ancestor = jmp(jump_table, node, k);
        cout << ancestor + 1 << endl; // In ra 1-based
    }
    
    return 0;
}