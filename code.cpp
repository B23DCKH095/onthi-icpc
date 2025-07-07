#include <bits/stdc++.h>
using namespace std;

const int maxn =2e5 + 10;
int sieve[maxn];
int n;
void calc(){
    for(int x = 2 ; x <= n ; x++){
        if(sieve[x])continue;
        for(int u = 2*x ; u <= n ;u += x){
            sieve[u] = x;
        }
    }
}
int main(){
    cin >> n;
    calc();
    for(int i =2; i <= 20 ; i++) cout << sieve[i] <<" ";
}