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
    bool isonepre(TreeNode *root){
        if(root==nullptr)return false;
        if(root->val==1)return true;
        return isonepre(root->left)||isonepre(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr)return nullptr;
        if(!isonepre(root->left))root->left = nullptr;
        if(!isonepre(root->right))root->right = nullptr;

        pruneTree(root->left);
        pruneTree(root->right);

        if(root->left==nullptr and root->right==nullptr and root->val==0){
            return nullptr;
        }
        return root;
    }
};