/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 */

// @lc code=start
class Solution {
public:
    int helper(vector<int> rating){
        int n = rating.size();
        vector<int> greater(n,0);
        vector<int> less(n,0);

        for(int i=0;i<rating.size();i++){
            for(int j=i+1; j<rating.size();j++){
                if(rating[j] > rating[i])
                    greater[i]++;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i-1; j>=0;j--){
                if(rating[j] < rating[i])
                    less[i]++;
            }
        }

        int sum = 0;
        for(int i=0;i<n;i++)
            sum += (greater[i] * less[i]);

        return sum;
    }

    int numTeams(vector<int>& rating) {
        int ans = 0;
        ans += helper(rating);
        reverse(rating.begin(),rating.end());
        ans += helper(rating);

        return ans;
    }
};
// @lc code=end

