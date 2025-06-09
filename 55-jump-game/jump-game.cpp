class Solution {
public:
    bool canJump(vector<int>& nums) {
        int vl = nums[0];
        if(nums.size()==1){
            return true;
        }
        if(vl==0)return false;
        for(int i = 1;i<nums.size();i++){
            vl--;
            vl = max(vl,nums[i]);
            if(i==nums.size()-1)return true;
            if(vl==0)return false;
        }
        return false;

    }
};