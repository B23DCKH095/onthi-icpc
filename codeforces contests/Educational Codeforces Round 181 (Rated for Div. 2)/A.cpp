#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    if(s.size() < 3) return false;
    for(int i = 0 ;i < s.size() - 2; i ++){
        if(s.substr(i,3) == "FFT" || s.substr(i,3) == "NTT") return true;
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        while(check(s)){
            for(int i =0 ;i < s.size() - 2; i++){
                if(s.substr(i,3) == "FFT" ) swap(s[i+1],s[i+2]);
                if(s.substr(i,3) == "NTT" ) swap(s[i],s[i+1]);
            }
        }
        cout << s << endl;
    }
}