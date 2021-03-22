/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 */

// @lc code=start
class CombinationIterator {
public:
    void nextComb(){
        for(int i=str.size()-1; i>0;i--){
            if(!combs[i] && combs[i-1]){
                swap(combs[i], combs[i-1]);
                sort(combs.begin() + i + 1, combs.begin() + str.size(), greater<>());
                return;
            }
        }
        has = false;
    }


    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        length = combinationLength;

        for(int i=0;i<characters.size();i++)
            combs.push_back(i < length);
    }
    
    string next() {
        string ret = "";
        for(int i=0;i<combs.size();i++)
            if(combs[i])
                ret.push_back(str[i]);

        nextComb();
        return ret;
        
    }
    
    bool hasNext() {
        return has;
    }

private:
    string str;
    int length;
    bool has = true;
    vector<bool> combs;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

/*
1 1 1 0 0 (0 0 0 0 0 0 0 0 0 0) => abc
1 1 0 1 0 (0 0 0 0 0 0 0 0 0 0) => abd
1 1 0 0 1 (0 0 0 0 0 0 0 0 0 0) => abe
1 0 1 1 0 (0 0 0 0 0 0 0 0 0 0) => acd
1 0 1 0 1 (0 0 0 0 0 0 0 0 0 0) => ace
1 0 0 1 1 (0 0 0 0 0 0 0 0 0 0) => ade
0 1 1 1 0 (0 0 0 0 0 0 0 0 0 0) => bcd
0 1 1 0 1 (0 0 0 0 0 0 0 0 0 0) => bce
0 1 0 1 1 (0 0 0 0 0 0 0 0 0 0) => bde
0 0 1 1 1 (0 0 0 0 0 0 0 0 0 0) => cde
*/