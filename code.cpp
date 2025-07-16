#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ordered_set<int> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "INSERT") {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if (cmd == "DELETE") {
            int x;
            cin >> x;
            auto it = s.find(x);
            if (it != s.end()) {
                s.erase(it);
            }
        }
        else if (cmd == "ORDER") {
            int x;
            cin >> x;
            cout << s.order_of_key(x) << '\n';
        }
        else if (cmd == "FIND") {
            int k;
            cin >> k;
            if (k >= 0 && k < (int)s.size()) {
                cout << *s.find_by_order(k) << '\n';
            }
        }
    }

    return 0;
}