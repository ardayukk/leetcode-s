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
    int minDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return minDepthHelper(root);
    }
    int minDepthHelper(TreeNode* root) {
        
        if(root == nullptr){
            return INT_MAX / 2;
        }
        if(root -> left == nullptr && root -> right == nullptr){
            return 1;
        }
        return 1 + min(minDepthHelper(root-> left), minDepthHelper(root -> right));
    }
};