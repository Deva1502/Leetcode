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
TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int &idx,int start,int end){
    if(start>end)return nullptr;
    int vl = preorder[idx];
    int i = start;
    for(;i<=end;i++){
        //finding index where vl is present in inorder -->left to that ind will left side tree and right will be right side
        if(vl==inorder[i]){
            break;
        }
    }
    idx++;
    TreeNode* root = new TreeNode(vl);
    root->left = solve(preorder,inorder,idx,start,i-1);
    root->right = solve(preorder,inorder,idx,i+1,end);
    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return solve(preorder,inorder,idx,0,n-1);
    }
};