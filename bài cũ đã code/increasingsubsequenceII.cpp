#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
 
const int maxn = 2e5 + 10;
ll tree[maxn];
int n;
 
ll sum(int k){
	ll s= 0;
	while(k >= 1){
		s = (s + tree[k])%mod;
		k -= k&-k;
	}
	return s;
}
void add(int k, ll x){
	while(k <= n){
		tree[k] = (tree[k] + x) % mod;
		k += k&-k;
	}
}
int main(){
	cin >> n;
	vector<int> a(n),b(n);
	for(int i = 0 ; i<n ; i++) cin >> a[i];
	b = a;
	sort(b.begin() , b.end());
	int cnt = 0;
	map<int,int> mp,ct;
	for(int x : b){
		if(!mp[x]) mp[x] = ++ cnt;
	}
	for(int x : a){
		ct[x]++;
		x = mp[x];
	}
	set<int> seen;

	for(int x : a){
		if(seen.find(x) == seen.end()){
			ll v = sum(x);
			add(x,v + ct[x]);
		}
		seen.insert(x);
	}
	cout << sum(n)<< endl;
}
