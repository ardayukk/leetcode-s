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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        
        ListNode* headcpy = head;
        int s = 0;
        while(headcpy){
            s++;
            headcpy = headcpy -> next;
        }
        k %= s;
        if(k == 0) return head;
        headcpy = head;

        for(int i = 0; i < s - k - 1; i++){
            head = head -> next;
        }
        ListNode* t = head;
        if(head -> next){
            t = head -> next;
        }
        ListNode* tcpy = t;
        while(t -> next){
            t = t -> next;
        }
        t -> next = headcpy;
        head->next = nullptr;
        return tcpy;
    }
};