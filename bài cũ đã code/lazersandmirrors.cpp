#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> point(n+2);
    vector<int> d(n+2,1e9);
    unordered_map<int,vector<int>> line[2];
    for(int i =0 ; i< n+2; i++){
        cin >> point[i].first >> point[i].second;
        line[0][point[i].first].push_back(i);
        line[1][point[i].second].push_back(i);
    }
    queue<pair<int,bool>> q;
    q.push({0,true});
    q.push({0,false});
    d[0] = 0;
    while(!q.empty()){
        int cur = q.front().first;
        bool beam = q.front().second;
        q.pop();
        int dir = (beam ? 0 : 1);
        int coord = (beam ? point[cur].first : point[cur].second);
        for(int p : line[dir][coord]){
            if(d[p] == 1e9){
                d[p] = d[cur] + 1;
                q.push({p,!beam});
            }
        }
    }
    cout << (d[1] == 1e9 ? -1 : d[1] - 1)<< endl;
}