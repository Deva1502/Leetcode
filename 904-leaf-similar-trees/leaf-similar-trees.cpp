/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void leaf(TreeNode* root, vector<int>& p) {
        if(root==nullptr)return ;

        if (root->left ==nullptr and root->right==nullptr) { // leaf node
            p.push_back(root->val);
        }
        leaf(root->left, p);
        leaf(root->right, p);

        // return p;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        leaf(root1, a);
        vector<int> b;
        leaf(root2, b);
        if (root1 == nullptr and root2 == nullptr)
            return true;
        if ((root1 == nullptr and root2 != nullptr) ||
            (root1 and root2 == nullptr))
            return false;
        return a == b;
    }
};