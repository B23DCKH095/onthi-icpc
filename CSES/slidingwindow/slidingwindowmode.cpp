#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i= 0; i <n ; i++) cin >> a[i];
    priority_queue<edges> q;
    for(int i =0 ;i < k; i++){
        q.push({a[i]});
        fre[a[i]]++;
    }
    for(int i = k ; i< n ; i++){
        fre[a[i-k]]--;
        fre[a[i]] ++;
        cout << q.top().x <<" ";
    }
}