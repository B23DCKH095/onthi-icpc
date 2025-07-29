#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, int n, vector<vector<int>>& board) {
    return x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1;
}

int countMoves(int x, int y, int n, vector<vector<int>>& board) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, n, board)) count++;
    }
    return count;
}

bool knightTour(int n, vector<vector<int>>& board, int x, int y, int move) {
    if (move == n*n) return true;
    
    vector<pair<int, int>> nextMoves;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, n, board)) {
            int degree = countMoves(nx, ny, n, board);
            nextMoves.emplace_back(degree, i);
        }
    }
    
    // Sắp xếp theo số nước đi tiếp theo tăng dần (Warnsdorf)
    sort(nextMoves.begin(), nextMoves.end());
    
    for (auto& p : nextMoves) {
        int i = p.second;
        int nx = x + dx[i];
        int ny = y + dy[i];
        board[nx][ny] = move;
        if (knightTour(n, board, nx, ny, move+1)) return true;
        board[nx][ny] = -1; // backtrack
    }
    return false;
}

int main() {
    int n = 8; // Kích thước bàn cờ
    vector<vector<int>> board(n, vector<int>(n, -1));
    
    int start_x = 0, start_y = 0; // Vị trí bắt đầu
    cin >> start_y>> start_x;
    --start_y , --start_x;
    board[start_x][start_y] = 0;
    
    if (knightTour(n, board, start_x, start_y, 1)) {
        // In kết quả
        for (auto& row : board) {
            for (int val : row) cout << val +1<<" ";
            cout << endl;
        }
    } else {
        cout << "Không tìm thấy hành trình" << endl;
    }
    
    return 0;
}