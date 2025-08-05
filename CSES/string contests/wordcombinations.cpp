#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
/**
 * Author: Simon Lindholm
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description: Various self-explanatory methods for string hashing.
 * Use on Codeforces, which lacks 64-bit support and where solutions can be hacked.
 * Status: stress-tested
 */
#pragma once

typedef uint64_t ull;
static int C; // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
        int x; B b; A(int x=0) : x(x), b(x) {}
        A(int x, B b) : x(x), b(b) {}
        A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
        A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
        A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
        explicit operator ull() { return x ^ (ull) b << 21; }
        bool operator==(A o) const { return (ull)*this == (ull)o; }
        bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

struct HashInterval {
        vector<H> ha, pw;
        HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
                pw[0] = 1;
                rep(i,0,sz(str))
                        ha[i+1] = ha[i] * C + str[i],
                        pw[i+1] = pw[i] * C;
        }
        H hashInterval(int a, int b) { // hash [a, b)
                return ha[b] - ha[a] * pw[b - a];
        }
};

vector<H> getHashes(string& str, int length) {
        if (sz(str) < length) return {};
        H h = 0, pw = 1;
        rep(i,0,length)
                h = h * C + str[i], pw = pw * C;
        vector<H> ret = {h};
        rep(i,length,sz(str)) {
                ret.push_back(h = h * C + str[i] - pw * str[i-length]);
        }
        return ret;
}
const int mod = 1e9 + 7;
H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

#include <sys/time.h>
int main() {
        timeval tp;
        gettimeofday(&tp, 0);
        C = (int)tp.tv_usec; // (less than modulo)
        assert((ull)(H(1)*2+1-3) == 0);
        
        string s;
        cin >> s;
        
        HashInterval hi(s);
        int n = sz(s);
        vector<ll> dp(n+1,0);
        dp[0] = 1;
        int k;
        cin >> k;
        while(k--){
            string t;
            cin >> t;
            H r = hashString(t);
            int i = 0;
            //fix 
            while(i <= n){
                H l = hi.hashInterval(i,i+sz(t));
                if((ull)l == (ull)r) dp[i+sz(t)] = (dp[i+sz(t)] + dp[i])%mod;
                i += sz(t);
            }
        }
        cout << dp[n] <<endl;
}