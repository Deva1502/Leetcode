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
TreeNode*solve(TreeNode* root, int val, int depth,int cur){
    if(root ==nullptr)return nullptr;
    if(cur==depth-1){
        TreeNode* lfttmp = root->left;
        TreeNode* rttmp = root->right;
        root->left = new TreeNode(val);
        root->right = new TreeNode(val);
        root->left->left = lfttmp;
        root->right->right = rttmp;
        return root;
    }
    solve(root->left,val,depth,cur+1);
    solve(root->right,val,depth,cur+1);
    return root;
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int curr = 1;
        if(depth==1){
            TreeNode* vl = new TreeNode(val);
            vl->left = root;
            return vl;
        }
        return solve(root,val,depth,curr);

    }
};