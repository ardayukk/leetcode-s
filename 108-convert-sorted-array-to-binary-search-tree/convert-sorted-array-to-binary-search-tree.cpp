/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return nullptr;
        else if(n == 1) return new TreeNode(nums[0]);
        else{
            int mid = n / 2;

            TreeNode* head = new TreeNode(nums[n/2]);

            vector<int> first(nums.begin(), nums.begin() + mid);
            vector<int> second(nums.begin() + mid + 1, nums.end());

            head -> left = sortedArrayToBST(first);
            head -> right = sortedArrayToBST(second);
            return head;
        }
        return nullptr;
    }
};