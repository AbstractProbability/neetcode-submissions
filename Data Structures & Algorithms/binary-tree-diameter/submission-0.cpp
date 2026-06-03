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
    int depth(TreeNode *root, int &max_diam)
    {
        if (!root) { return 0; }

        int ldia = depth(root->left, max_diam);
        int rdia = depth(root->right, max_diam);
        max_diam = max(max_diam, ldia+rdia+1);

        return max(ldia, rdia)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diam = 0;
        depth(root, max_diam);
        return max_diam-1;
    }
};
