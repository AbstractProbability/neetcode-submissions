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
    void recurse(TreeNode *root, vector<int> &ret, int &maxlevel, int level)
    {
        if (!root) {
            return;
        }
        if (level > maxlevel) {
            maxlevel = level;
            ret.push_back(root->val);
        }
        recurse(root->right, ret, maxlevel, level+1);
        recurse(root->left, ret, maxlevel, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        int maxlevel = 0;
        recurse(root, ret, maxlevel, 1);
        return ret;
    }
};
