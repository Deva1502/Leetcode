class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int n = q.size();
            long long min_index = q.front().second; // for index normalization
            long long first, last;

            for (int j = 0; j < n; j++) {
                auto i = q.front();
                q.pop();
                long long cur_index = i.second - min_index; // to prevent overflow

                if (j == 0) first = cur_index;
                if (j == n - 1) last = cur_index;

                if (i.first->left) q.push({i.first->left, 2LL * cur_index + 1});
                if (i.first->right) q.push({i.first->right, 2LL * cur_index + 2});
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};
