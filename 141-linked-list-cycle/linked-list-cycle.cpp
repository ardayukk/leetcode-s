class Solution {
public:
    bool hasCycle(ListNode *head) {
        for (int i = 0; i < 10010; i++) {
            if (head == nullptr) return false;
            head = head->next;
        }
        return true;
    }
};