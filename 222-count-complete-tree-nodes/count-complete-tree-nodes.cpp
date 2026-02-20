class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int h = height(root);                 // levels count, e.g. single node => 1
        if (h == 1) return 1;

        int lastLevelCount = 1 << (h - 1);    // 2^(h-1)
        int l = 0;
        int r = lastLevelCount - 1;

        // Find the last index on last level that exists
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (exists(root, h, mid)) {
                l = mid + 1;                  // mid exists, go right
            } else {
                r = mid - 1;                  // mid doesn't exist, go left
            }
        }

        // nodes above last level + nodes in last level
        // above last level = 2^(h-1) - 1
        int above = (1 << (h - 1)) - 1;
        int inLast = l;                       // l is first missing, so existing count = l
        return above + inLast;
    }

private:
    // height in levels by going leftmost
    int height(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }

    // does node at last-level index idx exist?
    // h = total levels. We need to take (h-1) steps from root to reach last level.
    bool exists(TreeNode* root, int h, int idx) {
        TreeNode* cur = root;
        int bit = 1 << (h - 2);               // highest decision bit for last level
        while (cur != nullptr && bit > 0) {
            if (idx & bit) cur = cur->right;
            else           cur = cur->left;
            bit >>= 1;
        }
        return cur != nullptr;
    }
};