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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) { return vector<vector<int>>(); }
        vector<vector<int>> ret;
        vector<queue<TreeNode *>> q(2);
        q[0].push(root);
        while (!q[0].empty() || !q[1].empty()) {
            if (!q[0].empty()) { ret.push_back(vector<int>()); }
            while (!q[0].empty()) {
                TreeNode *u = q[0].front();
                q[0].pop();
                if (!u) { continue; }
                ret[ret.size()-1].push_back(u->val);
                q[1].push(u->left);
                q[1].push(u->right);
            }
            if (ret[ret.size()-1].empty()) { ret.pop_back(); }
            if (!q[1].empty()) { ret.push_back(vector<int>()); }
            while (!q[1].empty()) {
                TreeNode *u = q[1].front();
                q[1].pop();
                if (!u) { continue; }
                ret[ret.size()-1].push_back(u->val);
                q[0].push(u->left);
                q[0].push(u->right);
            }
            if (ret[ret.size()-1].empty()) { ret.pop_back(); }
        }
        return ret;
    }
};
