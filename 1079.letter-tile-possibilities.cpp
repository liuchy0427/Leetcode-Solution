/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
class Solution {
    int ans = 0;
public:
    void recursive(int count[]){
        for(int i=0;i<26;i++){
            if(count[i] > 0){
                count[i]--;
                ans++;
                // cur.push_back(i + 'A');
                // cout<<cur<<endl;

                recursive(count);
                // cur.pop_back();
                count[i]++;
            }
        }
    }


    int numTilePossibilities(string tiles) {
        if(tiles.size() < 1) return 0;
        if(tiles.size() == 1) return 1;

        int count[26] = {0};

        for(int i=0;i<tiles.size();i++)
            count[tiles[i] - 'A']++;

        recursive(count);

        return ans;
    }
};
// @lc code=end

