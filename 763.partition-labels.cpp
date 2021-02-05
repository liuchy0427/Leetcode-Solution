/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        vector<int> ans;
        
        for(int i=0;i<s.size();i++)
            mp[s[i]] = i;
        
        int maxIdx = -1, lastIdx = 0;

        for(int i=0;i<s.size();i++){
            maxIdx = max(maxIdx,mp[s[i]]);

            if(i == maxIdx){
                ans.push_back(maxIdx - lastIdx + 1);
                lastIdx = i + 1;
            }
        }

        return ans;
    }
};
// @lc code=end

