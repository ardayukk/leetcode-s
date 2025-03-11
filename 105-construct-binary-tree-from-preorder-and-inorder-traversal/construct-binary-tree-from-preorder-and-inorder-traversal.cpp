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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return nullptr;
        }
        int a = preorder[0];
        TreeNode* root = new TreeNode(a);

        vector<int> preorderLeft;
        
        vector<int> preorderRight;
        
        vector<int> inorderLeft;
        
        vector<int> inorderRight;
        
        int i = 0;
        
        while(inorder[i] != a){
            inorderLeft.push_back(inorder[i]);
            i++;
        }

        i++;
        int j;

        for(j = 1; j < i; j++){
            preorderLeft.push_back(preorder[j]);
        }

        for(; i < inorder.size(); i++){
            inorderRight.push_back(inorder[i]);
        }

        for(; j <preorder.size(); j++){
            preorderRight.push_back(preorder[j]);
        }

        root -> left = buildTree(preorderLeft, inorderLeft);
        root -> right = buildTree(preorderRight, inorderRight);
        return root;
    }
};