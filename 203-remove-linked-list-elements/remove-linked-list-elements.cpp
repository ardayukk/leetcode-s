class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next;  // remove cur
                cur = prev->next;        // don't move prev
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};