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
long sm = -1,ans = -1;

int mod = 1e9+7;
    int totsm(TreeNode*root){
        if(root==nullptr){
            return 0;

        }
        int lftsm = totsm(root->left);
        int rtsm = totsm(root->right);

        int vl = lftsm+rtsm+root->val;
        return vl;
    }
    int solve(TreeNode *root){
        if(root==nullptr)return 0;
        int lft = solve(root->left);
        int rt = solve(root->right);
        long vl = root->val+lft+rt;
        ans = max(vl*(sm-vl),ans);

        return vl;
    }
    int maxProduct(TreeNode* root) {
        if(root==nullptr)return 0;
        sm = totsm(root);
        solve(root);

        return ans%mod;

    }
};