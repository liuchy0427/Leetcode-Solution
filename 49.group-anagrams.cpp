/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        if (strs.size() <= 1)
            return {strs};

        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto x : mp)
        {
            ans.push_back(x.second);
        }

        return ans;
    }
};
// @lc code=end
