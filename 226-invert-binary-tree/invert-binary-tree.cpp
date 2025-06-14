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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)return nullptr;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            auto i = q.front();
            q.pop();
            swap(i->left,i->right);;
            if(i->left)q.push(i->left);
            if(i->right)q.push(i->right);
        }
        return root;
    }
};