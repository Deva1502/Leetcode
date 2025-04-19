class Solution {
public:
    typedef long long ll;
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ll ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int left =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
                nums.begin();
            int right =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
                nums.begin();
            ans += (right - left);
        }
        return ans;
    }
};