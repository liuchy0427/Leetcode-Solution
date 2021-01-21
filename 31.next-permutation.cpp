/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int k, l;

        for (k = nums.size() - 1; k > 0; k--)
            if (nums[k] > nums[k - 1])
                break;
        k--;
        cout << k << endl;
        if (k < 0)
            reverse(nums.begin(), nums.end());
        else
        {
            for (l = nums.size() - 1; l >= 0; l--)
                if (nums[l] > nums[k])
                    break;

            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
// @lc code=end