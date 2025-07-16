#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// BeginCodeSnip{BIT (from PURS module)}
template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	void set(int ind, int val) { add(ind, val - arr[ind]); }

	void add(int ind, int val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};
// EndCodeSnip

vector<vector<int>> neighbors;
vector<int> start;
vector<int> end;
int timer = 0;

void euler_tour(int at, int prev) {
	start[at] = timer++;
	for (int n : neighbors[at]) {
		if (n != prev) { euler_tour(n, at); }
	}
	end[at] = timer;
}

int main() {
	int node_num;
	int query_num;
	std::cin >> node_num >> query_num;

	vector<int> vals(node_num);
	for (int &v : vals) { std::cin >> v; }

	neighbors.resize(node_num);
	for (int e = 0; e < node_num - 1; e++) {
		int n1, n2;
		std::cin >> n1 >> n2;
		neighbors[--n1].push_back(--n2);
		neighbors[n2].push_back(n1);
	}

	start.resize(node_num);
	end.resize(node_num);
	euler_tour(0, -1);

	BIT<long long> bit(node_num);
	for (int i = 0; i < node_num; i++) { bit.set(start[i], vals[i]); }
	for (int q = 0; q < query_num; q++) {
		int type;
		std::cin >> type;
		if (type == 1) {
			int node, val;
			std::cin >> node >> val;
			bit.set(start[--node], val);
		} else if (type == 2) {
			int node;
			std::cin >> node;
			long long end_sum = bit.pref_sum(end[--node] - 1);
			long long start_sum;
			if (start[node] == 0) {
				start_sum = 0;
			} else {
				start_sum = bit.pref_sum(start[node] - 1);
			}
			cout << end_sum - start_sum << '\n';
		}
	}
}