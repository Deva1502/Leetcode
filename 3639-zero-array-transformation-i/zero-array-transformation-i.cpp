class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (const auto& query : q) {
            int l = query[0];
            int k = query[1];
            diff[l]--;
            if (k + 1 < n) {
                diff[k + 1]++;
            }
        }
        int decrement = 0;
        for (int i = 0; i < n; i++) {
            decrement += diff[i];
            nums[i] += decrement;
            if(nums[i]>0)return false;
        }
        
        
        return true;
    }
};