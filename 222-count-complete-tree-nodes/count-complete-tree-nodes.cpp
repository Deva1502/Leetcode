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
    int cntlftht(TreeNode* root) {
        int lh = 0;
        TreeNode*temp =  root;
        while (temp!=nullptr) {

            temp = temp->left;
            lh++;
        }
        return lh;
    }
    int cntrhtht(TreeNode* root) {
        int rh = 0;
        TreeNode*temp =  root;
        while (temp!=nullptr) {

            temp = temp->right;
            rh++;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int lh = cntlftht(root);
        int rh = cntrhtht(root);

        if (lh == rh) {
            return (pow(2, lh) - 1);
        }

        int a = countNodes(root->left);
        int b = countNodes(root->right);
        return a + b + 1;
    }
};