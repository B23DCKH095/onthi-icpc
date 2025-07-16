#include <bits/stdc++.h>
using namespace std;

int p[1001];
int succ(int x,int k){
    if(k==1) return p[x];
    return succ(succ(x,k/2),k/2);
}
int count(int x){
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
    return a;
}
int main(){
    int n;
    cin >> n;
    for(int i =1; i <= n ;i++){
        int a;
        cin >> a;
        p[i] = a;
    }
    for(int i =1 ;i <= n ;i++) cout << count(i) << " ";
}