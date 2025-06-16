class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int a = nums[0];
        int ans = -1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]<=a)a = nums[i];
            else ans = max(ans,nums[i]-a);
        }
        return ans;
    }
};