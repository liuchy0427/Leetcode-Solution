/*
 * @lc app=leetcode id=1409 lang=cpp
 *
 * [1409] Queries on a Permutation With Key
 */

// @lc code=start
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m+1, 0);
        vector<int> ans;
        for(int i=0;i<m;i++)
            p[i+1] = i;

        for(int i=0;i<queries.size();i++){
            ans.push_back(p[queries[i]]);
            for(int j=1;j<p.size();j++)
                if(p[j] < p[queries[i]])
                    p[j]++;
            
            p[queries[i]] = 0;
        }
        return ans;

        // vector<int>v(m+1);
        // for(int i=0;i<m;i++)
        //     v[i+1]=i;
        // for(int j=0;j<queries.size();j++)
        // {
        //     int temp=v[queries[j]];
        //     for(int i=1;i<=m;i++)
        //         if(v[i]<temp)
        //             v[i]++;
        //     v[queries[j]]=0;
        //     queries[j]=temp;
        // }
        // return queries;
    }
};
// @lc code=end

