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
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            arr.push_back(curr -> val);
            if(curr -> right != nullptr){
                s.push(curr -> right);
            }
            if(curr -> left != nullptr){
                s.push(curr -> left);
            }
        }
        for(int i = 0; i < arr.size(); i++){
            int c = k - arr[i];
            if(c == arr[i]){
                continue;
            }
            TreeNode* hcpy = root;
            while(true){
                if(c == hcpy -> val){
                    return true;
                }
                if(c > hcpy -> val){
                    if(hcpy -> right == nullptr){
                        break;
                    }
                    hcpy = hcpy -> right;
                }
                else if(c < hcpy -> val){
                    if(hcpy -> left == nullptr){
                        break;
                    }
                    hcpy = hcpy -> left;
                }
            }

        }
        return false;
    }
};