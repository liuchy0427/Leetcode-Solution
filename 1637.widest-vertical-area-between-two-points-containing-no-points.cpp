/*
 * @lc app=leetcode id=1637 lang=cpp
 *
 * [1637] Widest Vertical Area Between Two Points Containing No Points
 */

// @lc code=start
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        sort(points.begin(),points.end());
        int ans = 0;
        for(int i=1;i<points.size();i++)
            ans = max(ans,points[i][0] - points[i-1][0]);
        return ans;
        // for(int i=0;i<points.size();i++)
        //     x.push_back(points[i][0]);
        
        // sort(x.begin(),x.end());

        // int maxwidth = 0;
        // int ans = 0;

        // for(int i=1;i<x.size();i++){
        //     ans = max(ans, x[i] - x[i-1]);
        // }

        // return ans;
    }
};
// @lc code=end

