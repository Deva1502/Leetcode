class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        sort(nums.begin(), nums.end());

        int k = (n + 1) / 2 - 1;
        int j = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans[i] = nums[k];
                k--;
            } else {
                ans[i] = nums[j];
                j--;
            }
        }

        nums = ans;
    }
};
