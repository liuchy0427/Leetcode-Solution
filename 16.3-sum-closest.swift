/*
 * @lc app=leetcode id=16 lang=swift
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
    func threeSumClosest(_ nums: [Int], _ target: Int) -> Int {
        var nums = nums.sorted()

        var res = (nums[0] + nums[1] + nums[2])

        for i in 0...nums.count - 2{
            var j = i + 1
            var k = nums.count - 1

            while j < k{
                var sum = nums[i] + nums[j] + nums[k]
                if abs(sum - target) < abs(res - target){
                    res = sum
                }
                
                if sum < target{
                    j += 1
                }else{
                    k -= 1
                }
            }
        }

        return res
    }
}
// @lc code=end

// sort(nums.begin(), nums.end());
//         int res = nums[0] + nums[1] + nums[2];
//         for(int i = 0; i < nums.size() - 2; i++){
//             int j = i + 1, k = nums.size() - 1;
//             while(j < k){
//                 int num = nums[i] + nums[j] + nums[k];
//                 if(abs(num - target) < abs(res - target)) res = num;
//                 if(num < target) j++;
//                 else k--;
//             }
//         }
//         return res;