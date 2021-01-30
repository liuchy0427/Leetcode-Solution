/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for(auto x:nums)
            mp[x]++;

        for(auto x:mp){
            pq.push(make_pair(x.second, x.first));
            if(pq.size() > mp.size() - k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }

        return ans;
        
        
    }
};
// @lc code=end

