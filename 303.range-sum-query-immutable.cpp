/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.size()<1)
            return ;
        arr.push_back(nums[0]);

        for(int i=0;i<nums.size();i++)
            arr.push_back(arr.back() + nums[i]);
    }
    
    int sumRange(int i, int j) {
        // for(auto a:arr)
        //     cout<<a<<" ";
        return arr[j+1] - arr[i];
    }

private:
    vector<int> arr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

