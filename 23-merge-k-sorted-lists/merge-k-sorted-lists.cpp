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
    // Custom comparator for the min-heap that compares ListNode pointers by their values.
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // smaller value has higher priority
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority queue (min-heap) to store the current heads of each list.
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        
        // Push the head of each non-empty list into the heap.
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        // Dummy node to help easily build the merged list.
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Continue until the heap is empty.
        while (!minHeap.empty()) {
            // Get the smallest node.
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Append the smallest node to our merged list.
            tail->next = smallest;
            tail = smallest;
            
            // If there is a next node in the list, push it into the heap.
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        // Return the head of the merged list.
        return dummy.next;
    }
};
