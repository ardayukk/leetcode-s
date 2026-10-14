class Solution {
public:
    int totalTilt = 0;

    int findTilt(TreeNode* root) {
        helper(root);
        return totalTilt;
    }

    int helper(TreeNode* root) {
        if (!root) return 0;

        int leftSum = helper(root->left);
        int rightSum = helper(root->right);

        totalTilt += abs(leftSum - rightSum);

        return root->val + leftSum + rightSum;
    }
};