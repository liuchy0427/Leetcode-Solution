/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return ans;
        vector<string> cur;
        dfs(0, s, cur);
        return ans;
    }

    void dfs(int index, string& s, vector<string>& cur){
        if(index == s.size())
            ans.push_back(cur);
        else{
            for(int i=index;i<s.size();i++){
                if(isPalindrome(s, index, i)){
                    cur.push_back(s.substr(index, i - index + 1));
                    // for(auto x:cur)
                    //     cout<<x<<" ";
                    // cout<<endl;
                    dfs(i + 1, s ,cur);
                    cur.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
// @lc code=end

