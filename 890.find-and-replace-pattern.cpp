/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

// @lc code=start
class Solution {
public:
    bool check(string s, string p){
        if(s.size() != p.size())     
            return false;

        map<char, char>  mp;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != p[i])
                    return false;
            }
            else
                mp[s[i]] = p[i];
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        // sort(patte rn.begin(), pattern.end());
        
        for(int i=0;i<words.size();i++){
            // string tmp = words[i];
            // sort(tmp.begin(),tmp.end());

            if (check(words[i],pattern) & check(pattern, words[i]))
                ans.push_back(words[i]);
        }

        return ans;
    }
};
// @lc code=end

