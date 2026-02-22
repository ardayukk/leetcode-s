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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; 
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }


    bool isPalindrome(ListNode* head) {
        ListNode* headcpy = head;
        int k = 0;
        while(headcpy){
            headcpy = headcpy -> next;
            k++;
        }
        headcpy = head;
        for(int i = 0; i <k / 2; i++){
            headcpy = headcpy -> next;
        }
        headcpy = reverseList(headcpy);

        for(int i = 0; i < k / 2; i++){
            if((head -> val) != headcpy -> val) return false;
            head = head -> next;
            headcpy = headcpy -> next;
        }
        return true;
    }
};