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
    bool isCompleteTree(TreeNode* root) {
        if(root==nullptr)return true;
        queue<TreeNode*>q;
        q.push(root);
        bool p = true;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it==nullptr)p = false;
            else{
                if(!p)return false;
                q.push(it->left);
                q.push(it->right);
            }
            
            
        }
        return true;
    }
};