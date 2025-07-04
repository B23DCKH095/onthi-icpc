#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int vao[n],ra[n];
    map<int,int> mp;
    int cnt= 0;
    vector<int> a;
    for(int i = 0 ; i < n; i++){
        cin >> vao[i] >> ra[i];
        a.push_back(vao[i]);
        a.push_back(ra[i]);
    }
    unique(a.begin() , a.end());
    sort(a.begin() ,a.end());
    for(int x : a){
        if(!mp[x]) mp[x] = ++ cnt;
    }
    int m = a.size();
    vector<int> pre_in(m+1,0) , pre_out(m+1,0);
    for(int x : vao) pre_in[mp[x]]++;
    for(int x : ra) pre_out[mp[x]]++;
    for(int i = 1 ; i <= m; i++){
        pre_in[i] += pre_in[i-1];
        pre_out[i] += pre_out[i-1];
    }
    int ans =0;
    for(int i = 1; i<= m ;i++) ans = max(ans,pre_in[i] - pre_out[i]);
    cout << ans << endl;

}