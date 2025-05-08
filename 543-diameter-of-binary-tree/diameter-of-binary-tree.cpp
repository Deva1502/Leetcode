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
int diam=0;
int height(TreeNode*node){
    if(node==nullptr)return 0;
    int lft = height(node->left);
    int rt = height(node->right);
    diam = max(diam,lft+rt);
    return max(lft,rt)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diam;
    }
};