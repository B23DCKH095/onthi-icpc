#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n ;i++) q.push(i);
    for(int i = 0 ;i <n ; i++){
        int k = q.front();
        q.pop();
        q.push(k);
        cout << q.front()<< " ";
        q.pop();
    }
}