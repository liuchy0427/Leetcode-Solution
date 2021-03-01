/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution {
private:
    vector<int> deck;
    default_random_engine seed;
public:
    Solution(vector<int>& nums) {
        deck = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return deck;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> tmp = deck;
        // std::shuffle(tmp.begin(), tmp.end(), seed);
        // return tmp;
        for(int i=tmp.size()-1; i>0;i--){
            auto idx = uniform_int_distribution<int>(0,i)(seed);
            swap(tmp[i], tmp[idx]);
        }

        return tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

