/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        helper("", 0, n, n);
        return ans;
    }


    void helper(string cur,int count, int n,int target){
        // cout<<cur.size()<<" "<<target*2<<endl;
        if(cur.size() == target * 2)
            ans.push_back(cur);
        else{
            if(count > 0)
                helper(cur + ")", count - 1, n-1, target);
            if(count < n)
                helper(cur + "(", count + 1, n, target);
        }
    }
};
// @lc code=end

