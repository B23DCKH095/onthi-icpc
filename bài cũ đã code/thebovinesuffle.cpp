#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int p[maxn];
bool vis[maxn];
bool on_stack[maxn];
bool cycle[maxn];
int cnt = 0;


void dfs(int x){
    vis[x] = true;
    on_stack[x] = true;
    int v = p[x];
    if(!vis[v]) dfs(v);
    else if(on_stack[v]){
        ++ cnt;
        cycle[v] = true;
    }
    on_stack[x] = false;
    return;
}
int main(){
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int v;
        cin >> v;
        p[i] = v;
    }
    for(int i =1; i<= n ; i ++){
        if(!vis[i]) dfs(i);
    }
    set<int> se;
    for(int i = 1; i<= n; i++){
        if(cycle[i]){
            se.insert(i);
            int a = p[i];
            int b = i;
            while(a != b){
                se.insert(a);
                a = p[a];
            }
        }
    
    }
    cout << se.size() << endl;
}