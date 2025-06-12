/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        if(root==p || root==q)return root;
        TreeNode *lft = lowestCommonAncestor(root->left,p,q);
        TreeNode *rgt = lowestCommonAncestor(root->right,p,q);
        //left me jayenge aur right me jayenge agar dono side mila to lca root hoga warna jis side p mila ya q mila vhi hoga
        if(lft!=NULL and rgt!=NULL)return root;
        if(lft!=NULL)return lft;
        return rgt;
    }
};