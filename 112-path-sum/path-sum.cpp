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
    bool solve(TreeNode* root, int targetSum, int sm) {
        if (root == nullptr)
            return false;
        //forgot this base case......./
        if (root->left == nullptr && root->right == nullptr)
            return sm + root->val == targetSum;

        bool lft = false, rgh = false;
        if (root->left)
            lft = solve(root->left, targetSum, sm + root->val);
        if (root->right)
            rgh = solve(root->right, targetSum, sm + root->val);

        return lft || rgh;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum, 0);
    }
};