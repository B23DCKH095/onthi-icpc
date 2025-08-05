#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e6 + 10;
const int MOD = 1e9 + 7;
 
ll c[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    sort(all(a));
    c[0] = 1;
    for(int i = 0; i <= x ; i ++){
        for(int j = 0 ; j < n ; j++){
            if(i + a[j] <= x){
                c[i + a[j]] = (c[i + a[j]] + c[i])%MOD;
            }
            else break;
        }
    }
    cout << c[x]%MOD << endl;
}