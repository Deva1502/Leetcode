class Solution {
public:
    int ans = 0;

    void solve(int cnt, TreeNode* root, char s) {
        if (root == nullptr) return;

        ans = max(ans, cnt);

        if (s == 'l') {
            if (root->right) solve(cnt + 1, root->right, 'r');
            if (root->left) solve(1, root->left, 'l');
        }
        if (s == 'r') {
            if (root->left) solve(cnt + 1, root->left, 'l');
            if (root->right) solve(1, root->right, 'r');
        }
    }

    int longestZigZag(TreeNode* root) {
        if (root == nullptr) return 0;

        ans = 0;
        if(root->left)
        solve(1, root->left, 'l');
        if(root->right)
        solve(1, root->right, 'r');

        return ans;
    }
};
