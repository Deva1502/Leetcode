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
//mirror ka matlab hai ki ek part ka left equal hona chahiye dusre part ke  right me
bool solve(TreeNode*a,TreeNode *b){
    if(a==nullptr and b==nullptr)return true;
    if(a==nullptr || b==nullptr)return false;
    if(a->val!=b->val)return false;
    return solve(a->left,b->right) and solve(a->right,b->left);

}
    bool isSymmetric(TreeNode* root) {
        TreeNode *a = root;
        return solve(root,a);
    }
};