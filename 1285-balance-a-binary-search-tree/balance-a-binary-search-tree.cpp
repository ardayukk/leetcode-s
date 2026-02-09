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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;

        storeInorder(root, inorder);
        
        int begin = 0;
        int end = inorder.size() - 1;
        TreeNode* newHead = createBalancedBST(inorder, begin, end);

        return newHead;
    }
    TreeNode* createBalancedBST(vector<int>& sortedVector, int begin, int end){
        if(end < begin){
            return nullptr;
        }

        int mid = begin + (end - begin) / 2;

        TreeNode* newNode = new TreeNode(sortedVector[mid]);
        newNode -> left = createBalancedBST(sortedVector, begin, mid - 1);
        newNode -> right = createBalancedBST(sortedVector, mid + 1, end);
        
        return newNode;
    }
    void storeInorder(TreeNode* root, vector<int>& vect){
        if(root == nullptr){
            return;
        }
        
        storeInorder(root -> left, vect);

        vect.push_back(root -> val);

        storeInorder(root -> right, vect);
    }
};