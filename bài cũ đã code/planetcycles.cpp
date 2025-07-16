#include <bits/stdc++.h>
using namespace std;
 
const int maxn  = 2e5 + 10;
int p[maxn];
int d[maxn];
int succ(int x,int k){
    if(k==1) return p[x];
    return succ(succ(x,k/2),k/2);
}
int count(int x){
    int length = 1;
    int a = p[x];
    int b = p[p[x]];
    while(a != b){
        a = p[a];
        b = p[p[b]];
    }
    a = x;
    while(a != b){
        a = p[a];
        b = p[b];
    }
    int first = a;
    return a;
    if(d[a]) return 0;
    b = p[a];
    while(a != b){
        b = p[b];
        ++ length;
    }
    d[a] = length;
    return length;
}
int main(){
    int n;
    cin >> n;
    for(int i =1; i <= n ;i++){
        int a;
        cin >> a;
        p[i] = a;
    }
    int ans = 0;
    for(int i =1 ;i <= n ;i++) cout << count(i) << endl;
}
