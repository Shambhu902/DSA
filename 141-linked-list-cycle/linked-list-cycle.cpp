
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto one = head, two = head;
        while(two && two->next){
            one = one->next;
            two = two->next->next;
            if(one == two) return true;
        }
        return false;
    }
};