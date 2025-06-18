class Solution {
public:
    unordered_map<string,int>mp;
    
    string solve(TreeNode *root, vector<TreeNode*>& ans) {
        if(root == nullptr) return "#";
        
        string ck = to_string(root->val) + ',' + solve(root->left, ans) + ',' + solve(root->right, ans);
        
        if(mp[ck] == 1) ans.push_back(root);
        mp[ck]++;
        
        return ck;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        solve(root, ans);
        return ans;
    }
};
