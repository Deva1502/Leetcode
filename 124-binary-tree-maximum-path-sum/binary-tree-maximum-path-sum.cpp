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
int ans;
int solve(TreeNode*root){
    if(root==nullptr)return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    int neeche_accha = l+r+root->val;//1
    int sirf_ek_accha = max(l,r)+root->val;//2
    int sirf_root_accha = root->val;//3

    ans = max({ans,neeche_accha,sirf_ek_accha,sirf_root_accha});

    return max(sirf_ek_accha,sirf_root_accha);//2,3 will taken
}
    int maxPathSum(TreeNode* root) {
        // if(root==nullptr)return 0;

        ans = INT_MIN;
        solve(root);

        return ans;
    }
};