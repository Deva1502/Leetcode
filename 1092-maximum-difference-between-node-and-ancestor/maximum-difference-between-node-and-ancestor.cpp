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

 //BRUTE FORCE
class Solution {
public:

    int ans ;
    void findmaxutil(TreeNode *root,TreeNode*child){
        if(root==nullptr || child==nullptr)return;

        ans = max(ans,abs(root->val-child->val));
        findmaxutil(root,child->left);
        findmaxutil(root,child->right);

    }
    void findMaxdiff(TreeNode *root){
        if(root==nullptr)return;
        findmaxutil(root,root->left);
        findmaxutil(root,root->right);

        findMaxdiff(root->left);
        findMaxdiff(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        ans = -1;
        findMaxdiff(root);


        return ans;
    }
};