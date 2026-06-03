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
    int depth(TreeNode *root)
    {
        if (!root) { return 0; }

        int ld = depth(root->left);
        int rd = depth(root->right);

        if (abs(ld-rd) > 1) { return -2; }
        return max(ld, rd)+1;
    }

    bool isBalanced(TreeNode* root) {
        if (depth(root) < 0) { return false; }
        return true;
    }
};
