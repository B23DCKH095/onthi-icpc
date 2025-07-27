#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> x;
int n;
int cnt;
void gen(int m,vector<pii> a,int last){
    if(m==3){
        bool ok = true;
        ll ret = (a[1].second - a[0].second)*(a[2].first - a[0].first) + (a[0].first - a[1].first)*(a[2].second - a[0].second);
        if(ret != 0) ++ cnt;
        return;
    }
    for(int i = last + 1; i < n ; i++){
        a.push_back(x[i]);
        gen(m+1,a,i);
        a.pop_back();
    }

}
int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     cin >> n;
     for(int i= 0; i <n ; i++){
        pii tmp;
        cin >> tmp.first >> tmp.second;
        x.push_back(tmp);
     }
     gen(0,{},-1);
     cout << cnt << endl;
}