#include <iostream>
#include <map>
using namespace std;

map<pair<int, int>, bool> cache;

bool isWinningPosition(int x, int y) {
    if (x < 1 || y < 1 || x > 15 || y > 15)
        return true;

    auto key = make_pair(x, y);
    if (cache.find(key) != cache.end())
        return cache[key];

    bool canWin = false;

    if (!isWinningPosition(x - 1, y - 2))
        canWin = true;

    if (!isWinningPosition(x + 1, y - 2))
        canWin = true;

    if (!isWinningPosition(x - 2, y + 1))
        canWin = true;

    if (!isWinningPosition(x - 2, y - 1))
        canWin = true;

    cache[key] = canWin;
    return canWin;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        if (isWinningPosition(x, y))
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }

    return 0;
}