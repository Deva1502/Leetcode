/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool p = false;
        while (!q.empty()) {
            int n = q.size();
            vector<int> vl;
            for (int i = 0; i < n; i++) {
                auto it = q.front();
                q.pop();
                vl.push_back(it->val);
                if (it->left)
                    q.push(it->left);
                if (it->right)
                    q.push(it->right);
            }
            if (p)
                reverse(vl.begin(), vl.end());
            p = !p;
            ans.push_back(vl);
        }

        return ans;
    }
};