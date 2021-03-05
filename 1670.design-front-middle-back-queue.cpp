/*
 * @lc app=leetcode id=1670 lang=cpp
 *
 * [1670] Design Front Middle Back Queue
 */

// @lc code=start
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        frontNode = NULL;
        midNode = NULL;
        backNode = NULL;

        count = 0;
    }
    
    void pushFront(int val) {
        ListNode* node = new ListNode(val);

        if(count == 0){
            frontNode = node;
            midNode = node;
            backNode = node;
        }
        else{
            frontNode->prev = node;
            node->next = frontNode;
            frontNode = node;

            if(count && count % 2 == 0)
                midNode = midNode->prev;
        }
        count++;
    }
    
    void pushMiddle(int val) {
        ListNode* node = new ListNode(val);

        if(count == 0){
            frontNode = node;
            midNode = node;
            backNode = node;
        }
        else{
            node->next = midNode->next;
            node->prev = midNode;
            midNode->next = node;

            if(count % 2 == 1)
                midNode = node;
        }
        count++;
    }
    
    void pushBack(int val) {
        ListNode* node = new ListNode(val);

        if(count == 0){
            frontNode = node;
            midNode = node;
            backNode = node;
        }
        else{
            backnode->next = node;
            node->prev = backNode;
            backnode = node;

            if(count && count % 2 == 0)
                midNode = midNode->next;
        }
        count++;
    }
    
    int popFront() {
        if(count == 0)
            return -1;
        
        ListNode* toDel = frontNode;

        toDel->next->prev = nullptr;
        


        count--;
    }
    
    int popMiddle() {
        
    }
    
    int popBack() {
        
    }
private:
    struct ListNode{
        int val;
        ListNode* next, *prev;
        ListNode(int _x, ListNode* _prev = NULL, ListNode* _next = NULL){
            val = _x;
            prev = _prev;
            next = _next;
        } 
    }

    ListNode *frontNode, *midNode, *backNode;
    int count;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end

