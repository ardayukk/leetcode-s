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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* headcpy = head;
        while(headcpy){
            n++;
            headcpy = headcpy -> next;
        }

        vector<int> v(n / 2);
        for(int i = 0; i < n / 2; i++){
            v[i] = head -> val;
            head = head -> next;
        }
        for(int i = n / 2; i < n; i++){
            v[n - i - 1] += head -> val;
            head = head -> next;
        }

        auto max_it = std::max_element(v.begin(), v.end());
        return *max_it;
    }
};