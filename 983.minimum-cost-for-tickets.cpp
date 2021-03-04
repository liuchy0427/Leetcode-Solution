/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int, int> tickets;
        tickets[1] = costs[0];
        tickets[7] = costs[1];
        tickets[30] = costs[2];

        int ans = 0;

        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<dp.size();i++){
            if(find(days.begin(), days.end(), i) == days.end())
                dp[i] = dp[i-1];
            else{
                for(auto t:tickets){
                    dp[i] = min(dp[i], dp[max(i-t.first, 0)]+t.second);
                }
                ans += dp[i];
            }
        }

        return dp[365];
    }
};
// @lc code=end

