class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = 0;
        for(int i = 1;i<nums.size();i++){
            ans = max(ans,abs(nums[i]-nums[i-1]));
        }
        int vl = abs(nums[0]-nums[nums.size()-1]);
        ans = max(ans ,vl);
        return ans;
    }
};