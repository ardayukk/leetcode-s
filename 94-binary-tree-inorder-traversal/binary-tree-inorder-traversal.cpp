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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        traverseTree(root, a);
        return a;
    }
    void traverseTree(TreeNode* root, vector<int>& vec){
        if(root == nullptr) return;

        traverseTree(root -> left, vec);

        vec.push_back(root -> val);

        traverseTree(root -> right, vec);

        return;


    }
};