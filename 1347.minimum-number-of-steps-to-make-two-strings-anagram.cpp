/*
 * @lc app=leetcode id=1347 lang=cpp
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
 */

// @lc code=start
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> smp;
        unordered_map<char, int> tmp;

        for(int i=0;i<s.size();i++){
            smp[s[i]]++;
            tmp[t[i]]++;
        }

        int ans = 0;
        for(auto x:smp){
            ans += max(x.second - tmp[x.first],0);
        }

        return ans;
    }
};
// @lc code=end

