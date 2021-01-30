/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // unordered_map<int, vector<int>> mp;
        // vector<vector<int>> ans;
        // int n = groupSizes.size();

        // for(int i=0;i<n;i++){
        //     mp[i].push_back(i);
        //     if(mp[i].size() == groupSizes[i]){
        //         ans.push_back(mp[i]);
        //         mp[i] = {};
        //     }
        // }
       
        // return ans;

        vector<vector<int>> res;
	unordered_map<int,vector<int>> groups;

	for(int i=0; i<groupSizes.size(); i++){
		auto& group=groups[groupSizes[i]];
		group.push_back(i);
		if(group.size()==groupSizes[i]){
			res.push_back(group);
			group={};
		}
	}
	return res;
    }
};
// @lc code=end

