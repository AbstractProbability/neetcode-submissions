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
    int recurse(TreeNode *root, int k, int &ans)
    {
        if (!root) { return 0; }
        int total = recurse(root->left, k, ans);
        total++;
        if (total == k) { ans = root->val; }
        total += recurse(root->right, k-total, ans);
        return total;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        recurse(root, k, ans);
        return ans;
    }
};
