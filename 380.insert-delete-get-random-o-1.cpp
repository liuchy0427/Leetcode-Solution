/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }else{
            mp[val] = randomSet.size();
            randomSet.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            randomSet[mp[val]] = randomSet.back();
            mp[randomSet.back()] = mp[val];

            mp.erase(val);
            randomSet.pop_back();
            return true;
        } 
        else
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
       
       return randomSet[uniform_int_distribution<>(0,randomSet.size()-1)(seed)];
    }
private:
    unordered_map<int, int>mp;
    vector<int> randomSet;

    default_random_engine seed;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

