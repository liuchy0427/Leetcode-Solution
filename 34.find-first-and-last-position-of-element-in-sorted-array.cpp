/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid;
        if (nums.size() < 1)
            return {-1, -1};
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;

            if (nums[mid] == target)
                break;
            else if (nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        // cout << "ans: " << lo << "->" << nums[lo] << endl;
        if (nums[mid] == target)
        {
            int l = mid, r = mid;
            while (r < nums.size() && nums[r] == target)
                r++;
            while (l >= 0 && nums[l] == target)
                l--;
            return {l + 1, r - 1};
        }
        else
            return {-1, -1};
    }
};
// @lc code=end
