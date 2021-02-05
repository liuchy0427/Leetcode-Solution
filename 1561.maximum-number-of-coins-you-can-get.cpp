/*
 * @lc app=leetcode id=1561 lang=cpp
 *
 * [1561] Maximum Number of Coins You Can Get
 */

// @lc code=start
class Solution {
public:
    int getSecond(vector<int> nums);
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.begin(), piles.end());

        int i=0, j=piles.size()-1;

        while(i < j){
            ans += piles[j-1];
            i++;
            j -= 2;
        }

        return ans;
    }
};
// @lc code=end

1 2 2 4 7 8
