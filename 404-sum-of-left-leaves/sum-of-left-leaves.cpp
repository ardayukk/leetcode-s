class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;

        int sum = 0;
        if(isLeaf(root -> left)){
            sum += root -> left -> val;
        }
        sum += sumOfLeftLeaves(root -> left);
        sum += sumOfLeftLeaves(root -> right);
        return sum;
    }
    bool isLeaf(TreeNode* node) {
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }
};