/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack {
    vector<int> stk;
    int stkSize = 0;
public:
    CustomStack(int maxSize) {
        stkSize = maxSize;
    }
    
    void push(int x) {
        if(stk.size() < stkSize){
            stk.push_back(x);
        }
    }
    
    int pop() {
        if(!stk.empty()){
            int tmp = stk.back();
            stk.pop_back();
            return tmp;
        }
        else
            return -1;
    }
    
    void increment(int k, int val) {
        int n = stk.size();
        int idx = min(k,n);

        for(int i=0;i<idx;i++)
            stk[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end

