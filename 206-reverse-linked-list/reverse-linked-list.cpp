class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre(NULL), *cur(head), *next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};