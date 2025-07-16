#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int P = 31; // 53 for case sensitivity
const int MOD = 1e9 + 9;
vector<long long> p_pow, h; // Powers of P and prefix hashes

// Function to compute modular exponentiation (a^b mod m)
ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Function to compute modular inverse using Fermat's Little Theorem
ll modinv(ll a, ll m) {
    return modpow(a, m - 2, m);
}

void compute_powers(int n) {
    p_pow.resize(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * P) % MOD;
}

ll compute_hash(string const& s) {
    ll hash_value = 0;
    for (int i = 0; i < s.size(); i++)
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
    return hash_value;
}

void calc(string const& s) {
    int n = s.size();
    h.resize(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
}

int main() {
    string t, s;
    cin >> t >> s;
    
    int k = t.size();
    if (k > s.size()) {
        cout << 0 << endl;
        return 0;
    }
    
    compute_powers(s.size());
    ll target_hash = compute_hash(t);
    calc(s);
    
    int cnt = 0;
    for (int i = 0; i <= s.size() - k; i++) {
        ll current_hash = (h[i + k] - h[i] + MOD) % MOD;
        ll inv_pow = modinv(p_pow[i], MOD);
        ll adjusted_hash = (current_hash * inv_pow) % MOD;
        
        if (adjusted_hash == target_hash)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}