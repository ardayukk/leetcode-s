/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<pair<Node*,int>> q;
        q.push({root, 1});
        int max = 1;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            auto in = p.second;
            auto v = p.first -> children;

            for(auto& i: v){
                q.push({i, in+1});
                max = in + 1;
            }
        }
        return max;
    }
};