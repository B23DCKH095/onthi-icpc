#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct AggStack {
    // Each element is stored as (value, current_min)
    stack<pair<ll, ll>> st;
    
    // Push a new number; compute the new min.
    void push(ll x) {
        ll cur = st.empty() ? x : min(st.top().second, x);
        st.push({x, cur});
    }
    
    // Pop the top element.
    void pop() {
        st.pop();
    }
    
    // Return the current minimum.
    ll agg() const {
        return st.top().second;
    }
};
struct AggQueue {
    AggStack in, out;
    
    // Push a new number llo the queue.
    void push(ll x) {
        in.push(x);
    }
    
    // Pop the oldest number.
    void pop() {
        if (out.st.empty()) {
            while (!in.st.empty()) {
                ll v = in.st.top().first;
                in.pop();
                out.push(v);
            }
        }
        out.pop();
    }
    
    // Query the current minimum.
    ll query() const {
        if (in.st.empty()) return out.agg();
        if (out.st.empty()) return in.agg();
        return min(in.agg(), out.agg());
    }
};
vector<ll> slideMin(const vector<ll>& a, ll K) {
    ll n = a.size();
    vector<ll> ans;
    AggQueue mq;  // Our aggregated queue mallains the minimum
    
    // Build the initial window of size K.
    for (ll i = 0; i < K; i++) {
        mq.push(a[i]);
    }
    ans.push_back(mq.query());
    
    // Slide the window: add a new element and remove the oldest.
    for (ll i = K; i < n; i++) {
        mq.push(a[i]);   // add new element
        mq.pop();        // remove element that's left the window
        ans.push_back(mq.query());
    }
    
    return ans;
}
int main(){
   ll n,k;
   cin >> n >> k;
   ll x,a,b,c;
   cin >> x >> a >> b >> c;
   vector<ll> v(n);
   v[0] = x;
   for(ll i = 1; i< n ; i++){
      v[i] =  (a*(v[i-1]%c) + b)%c;
      v[i] %= c;
   }
   vector<ll> ret = slideMin(v,k);
   ll s = 0;
   for(ll u : ret) s ^= u;
   cout << s << endl;
}