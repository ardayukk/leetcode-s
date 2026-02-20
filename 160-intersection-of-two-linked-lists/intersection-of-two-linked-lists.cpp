/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ac = 0;
        int bc = 0;
        ListNode* headAcpy = headA;
        ListNode* headBcpy = headB;
        while(headAcpy){
            ac++;
            headAcpy = headAcpy -> next;
        }
        while(headBcpy){
            bc++;
            headBcpy = headBcpy -> next;
        }

        headAcpy = headA;
        headBcpy = headB;

        if(ac > bc){
            while(ac != bc){
                headAcpy = headAcpy -> next;
                ac--;
            }
        }
        if(ac < bc){
            while(ac != bc){
                headBcpy = headBcpy -> next;
                bc--;
            }
        }
        while(ac > 0){
            if(headAcpy == headBcpy){
                return headAcpy;
            }
            headAcpy = headAcpy -> next;
            headBcpy = headBcpy -> next;
            ac--;
        }
        return nullptr;
    }
};