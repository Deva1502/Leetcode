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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inst,
                    int inend, int postst, int postend) {
        if (inst > inend)
            return nullptr;
        int vl = postorder[postend];
        TreeNode* root = new TreeNode(vl);
        int i = inst;
        for (; i <= inend; i++) {
            if (inorder[i] == vl)
                break;
        }
        int lftsize = i - inst;
        int rgtside = inend - i;

        root->left = solve(inorder, postorder, inst, i - 1, postst, postst + lftsize - 1);
        root->right = solve(inorder, postorder, i + 1, inend, postst + lftsize,postend - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        int inst = 0, inend = n - 1;
        int postst = 0, postend = n - 1;
        return solve(inorder, postorder, inst, inend, postst, postend);
    }
};