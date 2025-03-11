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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){
            return nullptr;
        }

        int a = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(a);
        int i = 0;
        vector<int> inOrderLeft;

        while(inorder[i] != a){
            inOrderLeft.push_back(inorder[i]);
            i++;
        }
        i++;
        vector<int> postOrderLeft;
        int j;
        for(j = 0; j < i - 1; j++){
            postOrderLeft.push_back(postorder[j]);
        }
        vector<int> inOrderRight;
        for(; i < inorder.size(); i++){
            inOrderRight.push_back(inorder[i]);
        }
        vector<int> postOrderRight;
        for(; j < inorder.size() -1; j++){
            postOrderRight.push_back(postorder[j]);
        }

        root -> left = buildTree(inOrderLeft, postOrderLeft);
        root -> right = buildTree(inOrderRight, postOrderRight);
        return root;
    }
};