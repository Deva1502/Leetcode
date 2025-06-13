class Solution {
public:
    int solve(TreeNode* a, int vl, int sm) {
        if (a == nullptr) {
            return sm;
        }
        vl = vl * 10 + a->val;

        if (a->left == nullptr && a->right == nullptr) {
            return sm + vl;
        }

        int leftSum = solve(a->left, vl, sm);
        int rightSum = solve(a->right, vl, sm);

        return leftSum + rightSum;
    }

    int sumNumbers(TreeNode* root) {
        int vl = 0;
        int sum = 0;
        if (root == nullptr) return 0;
        return solve(root, vl, sum);
    }
};
