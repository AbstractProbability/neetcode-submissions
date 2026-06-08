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
    int maxlen = -1001;
public:
    int maxPath(TreeNode *root)
    {
        if (!root) { return -1001; }
        int lmaxdpath = maxPath(root->left);
        int rmaxdpath = maxPath(root->right);
        maxlen = max(maxlen,  max(max(root->val, root->val+lmaxdpath+rmaxdpath), max(lmaxdpath, rmaxdpath)+root->val));

        cout << root->val << " " << lmaxdpath << " " << rmaxdpath << " " << maxlen << "\n";
        return max(root->val, max(lmaxdpath, rmaxdpath)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxlen;
    }
};
