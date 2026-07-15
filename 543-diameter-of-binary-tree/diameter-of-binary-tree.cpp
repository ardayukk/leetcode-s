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
    int depth(TreeNode* node) {
        if (node == nullptr) return 0;

        return 1 + max(depth(node->left), depth(node->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();

            int l = 0;
            int r = 0;

            if(top -> left != nullptr){
                l = depth(top -> left);
                q.push(top -> left);
            }
            if(top -> right != nullptr){
                r = depth(top -> right);
                q.push(top -> right);
            }
            diameter = max(r + l, diameter);

        }
        return diameter;
    }
};