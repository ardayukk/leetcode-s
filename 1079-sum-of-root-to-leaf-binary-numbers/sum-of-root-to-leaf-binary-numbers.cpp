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
    int strTonb(string s){
        int a = 0;
        int i = 0;
        // cout << s << endl;
        while(s[i] == 0) i++;
        for(; i < s.size(); i++){
            a += ((s[i]-'0') & 1);
            if(i != s.size() - 1){
                a <<=1;
            }
        }
        // cout << a <<endl;
        return a;

    }
    int sumRootToLeaf(TreeNode* root) {
        if(root == nullptr)return 0;
        if(root -> left == nullptr && root -> right == nullptr){
            return root -> val;
        }
        return sumRootToLeaf(root, "");
    }
    
    int sumRootToLeaf(TreeNode* root, string stringSoFar) {
        
        if(root -> left == nullptr && root -> right == nullptr) return strTonb(stringSoFar + to_string(root -> val));
        if(root -> left && root -> right){
            return sumRootToLeaf(root -> left, stringSoFar + to_string(root -> val)) + sumRootToLeaf(root -> right, stringSoFar + to_string(root -> val));
        }
        else if(root -> left){
            return sumRootToLeaf(root -> left, stringSoFar + to_string(root -> val));
        }
        else{
            return sumRootToLeaf(root -> right, stringSoFar + to_string(root -> val));
        }
        
    }
};