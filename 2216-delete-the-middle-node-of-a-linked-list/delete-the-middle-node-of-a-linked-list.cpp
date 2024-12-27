/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == nullptr){
            return nullptr;
        }
        ListNode* headCpy = head;
        int counter = 1;
        while(headCpy -> next != nullptr){
            headCpy = headCpy -> next;
            counter++;
        }
        headCpy = head;
        for(int i = 1; i < counter / 2; i++){
            headCpy = headCpy -> next;
        }
        ListNode* headCpyNext = headCpy -> next;
        headCpy -> next = headCpyNext -> next;
        return head;
    }
};