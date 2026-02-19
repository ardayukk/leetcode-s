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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        
        postorderTraversalHelper(root, vec);
        
        return vec;
    }
    void postorderTraversalHelper(TreeNode* root, vector<int>& vec) {
        if(root == nullptr){
            return;
        }

        
        postorderTraversalHelper(root -> left, vec);
        
        postorderTraversalHelper(root -> right, vec);
        
        vec.push_back(root -> val);
    }
};