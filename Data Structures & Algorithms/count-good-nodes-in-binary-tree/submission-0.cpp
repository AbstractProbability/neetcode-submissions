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
    void greatest_till_now(TreeNode *root, int gtn, int &total) {
        if (!root) { return; }
        if (root->val >= gtn) {
            total++;
            gtn = root->val;
        }
        greatest_till_now(root->left, gtn, total);
        greatest_till_now(root->right, gtn, total);
    }
    
    int goodNodes(TreeNode* root) {
        int gtn = root->val;
        int total = 0;
        greatest_till_now(root, gtn, total);
        return total;
    }
};
