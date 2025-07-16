#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> ret;
        for(int i = 0 ;i < k ; i++) s.insert(nums[i]);
        int n = nums.size();
        for(int i = k ; i< n ;i++){
            ret.push_back(*s.begin());
            s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
        }
        for(int x : ret) cout << x <<" ";
    }
};