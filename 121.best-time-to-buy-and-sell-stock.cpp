/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = INT_MIN;

        for(int i=0;i<prices.size();i++){
            minPrice = min(prices[i], minPrice);
            ans = max(prices[i] - minPrice, ans);
        }

        return ans;
    }
};
// @lc code=end

