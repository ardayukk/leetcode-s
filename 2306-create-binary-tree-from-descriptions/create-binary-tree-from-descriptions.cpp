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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> all;

        map<int,vector<vector<int>>> pc;

        for(auto& v: descriptions){
            pc[v[0]].push_back(v);
        }

        for(auto& v: descriptions){
            all.insert(v[0]);
            all.insert(v[1]);
        }
        for(auto& v: descriptions){
            all.erase(v[1]);
        }

        int x = *all.begin();

        TreeNode* t = new TreeNode(x);
        queue<TreeNode*> q;
        q.push(t);

        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            vector<vector<int>>& vvi = pc[top -> val];

            for(auto& v: vvi){
                if(v[2] == 1){
                    top -> left = new TreeNode(v[1]);
                    q.push(top -> left);
                }
                else{
                    top -> right = new TreeNode(v[1]);
                    q.push(top -> right);
                }
            }
        }

        return t;

    }
};