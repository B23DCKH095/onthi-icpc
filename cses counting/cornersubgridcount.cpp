#include <iostream>
#include <vector>
using namespace std;

const int N = 32; // Số cột xử lý cùng lúc (32-bit int)

int countBlackSubgridsBitOpt(const vector<vector<int>>& grid) {
    int n = grid.size();
    int blocks = (n + N - 1) / N; // Số khối cần xử lý
    vector<vector<unsigned>> color(n, vector<unsigned>(blocks, 0));

    // Chuyển đổi mỗi hàng thành dạng bit
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int block = j / N;
                int bit = j % N;
                color[i][block] |= (1 << bit);
            }
        }
    }

    int res = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            int count = 0;
            for (int k = 0; k < blocks; k++) {
                unsigned bits = color[a][k] & color[b][k];
                count += __builtin_popcount(bits);
            }
            res += count * (count - 1) / 2;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };
    cout << countBlackSubgridsBitOpt(grid) << endl; // Output: 6
    return 0;
}