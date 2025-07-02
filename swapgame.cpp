#include <bits/stdc++.h>
using namespace std;

unordered_set<string> vis;
unordered_map<string,int> d;

int x[12] = {1,2,4,5,7,8,1,2,3,4,5,6};
int y[12] = {2,3,5,6,8,9,4,5,6,7,8,9};

int main(){
    string s;
    char tmp;
    for(int i = 0 ; i< 9 ; i++) {
        cin >> tmp;
        s += tmp;
    }
    queue<string> q;
    string en = "123456789";

    d[s] = 0;
    vis.insert(s);
    q.push(s);

    while(!q.empty()){
        string u =q.front();
        q.pop();
        if(u == en){
            break;
        }
        for(int k = 0 ; k < 12 ; k++){
            string v = u;
            swap(v[x[k]-1],v[y[k]-1]);
            if(vis.find(v) == vis.end()){
                vis.insert(v);
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
    cout << d[en] << endl;
}