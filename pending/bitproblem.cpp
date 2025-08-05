/*
ID: USACO_template
LANG: C++
PROG: https://cses.fi/problemset/task/1654/
*/
#include <iostream>  //cin , cout
#include <fstream>   //fin, fout
#include <stdio.h>   // scanf , pringf
#include <cstdio>
#include <algorithm> // sort , stuff
#include <stack>     // stacks
#include <queue>     // queues
#include <map>
#include <string>
#include <string.h>
#include <set>

using namespace std;

typedef pair<int, int>          pii;
typedef vector<int>             vi;     /// adjlist without weight
typedef vector<pii>             vii;    /// adjlist with weight
typedef vector<pair<int,pii>>   vpip;   /// edge with weight
typedef long long               ll;

#define mp  make_pair
#define ff  first
#define ss  second
#define pb  push_back
#define sz(x)   (int)(x).size()

const int MOD = 1e9+7;  // 998244353;
const int MX  = 2e5+5;   //
const ll  INF = 1e18;    //

#define MAXV 200007
#define MAXE 100007

bool debug;

int N, Nbit;
int y[MAXV];
int a[1<<21];
int dp[1<<21][2];

int main() {
    debug = false;
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> N;
    int maxVal = -1;
    for(int i=0; i<N; i++) {
        int x; cin >> x;
        y[i] = x;
        a[x]++;
        dp[x][0]++; dp[x][1]++;
        maxVal = max(x, maxVal);
    }

    int x = 1;
    Nbit = 0;
    while(maxVal >= x) {x *=2; Nbit++;}
    if(debug) cout << Nbit << " " << x << endl;

    for(int i = 0; i < Nbit; ++i) {
        for(int mask = 0; mask < (1<<Nbit); ++mask){
            /// x|y=x means y is subset of x, and we are counting # of x's subset
            /// if x's bit i is 1, we need to add the subset where that bit is zero
            if(mask & (1<<i)) dp[mask][0] += dp[mask^(1<<i)][0];

            /// x&y=x means x is subset of y, and we are counting subperset
            /// if x's bit i is 1, y's bit i has to be 1
            /// if x's bit i is 0, y's but i can be either 1 or zero
            if(!(mask & (1<<i))) dp[mask][1] += dp[mask | (1<<i)][1];

            /// x&y!=0, means there is at least 1 overlap
            /// which means y can not be the subset of ~x
            /// so = N - (~x)|y, so we can use 1st result

        }
    }

    for(int i=0; i<N;i++) {
        int masking = (1<<Nbit) - 1;
        int y2 = y[i]^masking;
        cout << dp[y[i]][0] << " " << dp[y[i]][1] << " " << N - dp[y2][0] << endl;
    }

    if(debug) cout << endl << "EOL" << endl;

}