/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& a) {
        if(a.size()<2) return 0;
        sort(a.begin(), a.end());

        int ans = 0;
        int prev = a[0];
        
        for(int i=1;i<a.size();i++){
            if(prev >= a[i]){
                ans += (prev + 1 - a[i]);
                a[i] = prev + 1;
            }
            prev = a[i];
        }

        return ans;


    }
};
// @lc code=end

