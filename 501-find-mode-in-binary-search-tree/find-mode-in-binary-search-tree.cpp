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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> freq;
        queue<TreeNode*> s;
        s.push(root);
        int maxn = 0;
        while(!s.empty()){
            TreeNode* curr = s.front();
            s.pop();
            if(curr -> left) s.push(curr -> left);
            if(curr -> right) s.push(curr -> right);
            freq[curr -> val]++;
            maxn = max(maxn, freq[curr -> val]);
        }
        s.push(root);
        vector<int> ans;
        for(auto& [a,b] : freq){
            if(b == maxn){
                ans.push_back(a);
            }
        }
        return ans;

    }
};