class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy, *tail = &dummy;
        while (head) {
            int val = head->val;
            if (head->next && head->next->val == val) {
                while (head && head->val == val) head = head->next;
            } else {
                tail->next = head;
                tail = head;
                head = head->next;
            }
        }
        tail->next = nullptr;
        return dummy.next;
    }
};