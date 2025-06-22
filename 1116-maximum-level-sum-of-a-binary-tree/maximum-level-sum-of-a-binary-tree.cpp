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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr)return 0;

        int ans = 1;
        int vl = root->val;
        int c = 1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int sm = 0;
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                sm += it->val;
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            if(sm>vl){
                vl = sm;
                ans = c;
            }
            c++;
        }
        return ans;
    }
};