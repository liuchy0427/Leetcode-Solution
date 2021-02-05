/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
    // int target;
    // vector<vector<int>> ans;
    // vector<int> cur;

    // void recursive(vector<vector<int>> graph,int index){
    //     cur.push_back(index);

    //     if(index == target){
    //         ans.push_back(cur);
    //     }
    //     else{
    //         for(int i=0;i<graph[index].size();i++){
    //             recursive(graph, graph[index][i]);
    //         }
    //     }

    //     cur.pop_back();
    // }

    // vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    //     target = graph.size()-1;

    //     recursive(graph, 0);
    //     return ans;
    // }

    int target;
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<vector<int>>& graph, int currNode = 0) {
	    // updating tmp
        tmp.push_back(currNode);
		// and either updating res with it if target is met
        if (currNode == target) res.push_back(tmp);
		// or callling dfs again recursively
        else for (int node: graph[currNode]) {
            dfs(graph, node);
        }
        // backtracking with tmp
		tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        dfs(graph);
        return res;
    }
};
// @lc code=end

