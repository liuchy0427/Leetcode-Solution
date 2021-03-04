/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        if(arr.size() < 1) return 0;
        // if(arr.size() == 2) return arr[1] * arr[0];
        int ans = 0;
        vector<int> stk;
        stk.push_back(INT_MAX);

        for(int i=0;i<arr.size();i++){
            while(!stk.empty() && arr[i] > stk.back() ){
                int mid = stk.back();
                stk.pop_back();
                // cout<<arr[i]<<" "<<mid<<" "<<stk.back()<<endl;
                ans += mid * min(stk.back(), arr[i]);                
            }
            stk.push_back(arr[i]);
        }

        for(int i=2;i<stk.size();i++)
            ans += stk[i] * stk[i-1];

        return ans;
    }
};
// @lc code=end

