#include <bits/stdc++.h>

using namespace std;

int n, t_max;
vector<int> d;

bool works(int k){
    multiset<int> ms;
	// Add the first k durations of the dance...
    for(int i=0; i<k; i++){
        ms.insert(d[i]);
    }
	// Continue adding new cows until there aren't any to add left...
    for(int i=k; i<n; i++){
        int curBegin = *ms.begin();
        ms.insert(curBegin + d[i]);
		// Add the end time of the current cow to the multiset...
        ms.erase(ms.find(curBegin));
		// Delete the cow with the lowest ending time...
    }
    return (*(--ms.end()) <= t_max);
	// See if the largest ending time isn't more than t_max...
}

int main(){
	// File input
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> n >> t_max;
    for(int i=0; i<n; i++){
        int d_i; cin >> d_i;
        d.push_back(d_i);
    }
	// Binary Search on the Answer for k...
    int l = 1, r = n, ans = n;
    while(l < r){
        int m = l + (r-l) / 2;
        if(works(m)){
           ans = m;
           r = m;
        } else {
           l = m+1;
        }
    }
    cout << ans << endl;
}