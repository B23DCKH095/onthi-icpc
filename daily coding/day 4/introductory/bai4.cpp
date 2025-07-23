#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
     cin.tie(0)->sync_with_stdio(0);
     cin.exceptions(cin.failbit);
     string s;
     cin >> s;
     map<char,int> mp;
     for(char x : s) mp[x] ++;
     int cnt = 0;
     char c;
     for(auto x : mp){
        if(x.second%2 ==1) {
            ++ cnt;
            c = x.first;
        }
     }
     if(cnt > 1){
        cout <<"NO SOLUTION"<< endl;
     }
     if(cnt ==1){
        string s = "";
        for(auto x : mp){
            if(x.first != c){
                for(int i = 0; i < x.second/2 ; i++) s += x.first;
            }
        }
        string t = s;
        reverse(all(t));
        string ans = s;
        for(int i = 0; i < mp[c] ; i ++) ans += c;
        ans +=t;
        cout << ans << endl;
     }
     if(cnt ==0){
        string s = "";
        for(auto x : mp){
            for(int i = 0 ; i< x.second/2; i++) s += x.first;
        }
        string t =s;
        reverse(all(t));
        cout << s << t << endl;
     }
}