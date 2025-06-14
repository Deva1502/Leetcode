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
            //aise swap karenge ye samjhana hoga i actually have doubt that will i can or not btw we chave to swap by this way
            swap(i->left,i->right);;
            if(i->left)q.push(i->left);
            if(i->right)q.push(i->right);
        }
        return root;
    }
};