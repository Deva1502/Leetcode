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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if(root->left==nullptr and root->right==nullptr)return 1;//leaf node
        if(root->left==nullptr)return 1+minDepth(root->right);
        if(root->right==nullptr)return 1+minDepth(root->left);
        int lft = 1 + minDepth(root->left);
        int rt = 1 + minDepth(root->right);
        cout << lft << " " << rt << endl;
        return min(lft, rt);
    }
};