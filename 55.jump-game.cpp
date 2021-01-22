/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int index = nums.size() - 1;
        int steps = 1;

        while (index-- > 0)
        {
            if (nums[index] < steps)
                steps++;
            else
                steps = 1;
        }

        if (steps == 1)
            return true;
        else
            return false;
    }
};
// @lc code=end
