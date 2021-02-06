/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> stk;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')
                stk.push_back(s[i]);
            else{
                if(!stk.empty() && stk.back()=='(')
                    stk.pop_back();
                else
                    stk.push_back(s[i]);
            }
        }

        return stk.size();
    }
};
// @lc code=end

