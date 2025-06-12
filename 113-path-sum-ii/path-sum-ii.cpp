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
void solve(TreeNode* root, int targetSum,vector<vector<int>>&ans,vector<int>&vl, int sm){
    if(root==nullptr)return;
    vl.push_back(root->val);
    sm += root->val;
    if(root->left==nullptr and root->right==nullptr and sm==targetSum){
        ans.push_back(vl);
    }
    if(root->left){ solve(root->left,targetSum,ans,vl,sm);}
    if(root->right){solve(root->right,targetSum,ans,vl,sm);}
     vl.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>vl;
        int sm=0;
        solve(root,targetSum,ans,vl,0);


        return ans;
    }
};