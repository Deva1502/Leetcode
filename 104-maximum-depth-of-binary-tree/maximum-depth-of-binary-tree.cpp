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
    int maxDepth(TreeNode* root) {
           if(root==nullptr)return 0;
           int lft = 1 + maxDepth(root->left);
           int rt = 1 + maxDepth(root->right);
           cout<<lft<<" "<<rt;
           return max(lft,rt);
    }
};