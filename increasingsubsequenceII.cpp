#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int m = 1e9 + 7;
int main() {
		Tree<int> tree;

		int arr_len;
		cin >> arr_len;
		long long inv_num = 0;
		for (int i = 0; i < arr_len; i++) {
			int x;
			cin >> x;
			/*
			 * Calculate the # of elements in the tree
			 * that are greater than x.
			 * (.order_of_key(x) gives the # of elements less than x)
			 */
			inv_num += tree.order_of_key(x+1)+1;
            inv_num %= m;
			tree.insert(x);
	}
    cout << inv_num%m << endl;
}