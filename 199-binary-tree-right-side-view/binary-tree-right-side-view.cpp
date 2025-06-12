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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr)return ans;
        //level order traversal
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int x = 0;
            for(int i = 0;i<n;i++){
                auto it = q.front();
                q.pop();
                x = it->val;
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            ans.push_back(x);
        }
        return ans;
    }
};