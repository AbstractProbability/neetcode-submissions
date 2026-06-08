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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!p) { return q; }
        if (!q) { return p; }
        while (root != NULL) {
            if (root->val == q->val || root->val == p->val) { return root; }
            bool p1 = root->val > p->val;
            bool p2 = root->val > q->val;
            if ((p1 && !p2) || (!p1 && p2)) {
                return root;
            } else if (p1 && p2) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};
