/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string s = "1";
        string res = "", tmp = countAndSay(n-1);

        
        return helper(tmp);
    }

    string helper(string s){
        int i=0;
        char cur = s[0];
        int count = 0;
        string ret = "";
        while(i<s.size()){
            if(s[i] == cur)
                count++;
            else{
                ret += to_string(count);
                ret += cur;
                cur = s[i];
                count = 1;
            }
            i++;
        }
        ret += to_string(count) + cur;

        return ret;
    }
};
// @lc code=end

