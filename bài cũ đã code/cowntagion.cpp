#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> adj[maxn];
bool vis[maxn];
int days;
int c[maxn];
void dfs(int x,int p){
    vis[x] = true;
    c[x] = 1;
    int cnt = 0;
    for(int v : adj[x]){
        if(v == p) continue;
        ++ cnt;
        ++ days;
        dfs(v,x);
    }
    while(c[x] < cnt + 1) c[x] *=2;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i <n -1 ; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    for(int i =1 ; i<= n ;i++) days += log2(c[i]);
    cout << days << endl;
}