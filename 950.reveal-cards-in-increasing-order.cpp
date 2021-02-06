/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
 */

// @lc code=start
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());

        deque<int> d;
        d.push_back(deck[0]);
        // 逆序反推
        for(int i=1;i<deck.size();i++){
            // for(auto x:d)
            //     cout<<x<<" ";
            // cout<<endl;

            d.push_front(d.back());
            d.pop_back();
            d.push_front(deck[i]);
        }

        vector<int> ans(d.begin(),d.end());
        return ans;
    }
};
// @lc code=end

