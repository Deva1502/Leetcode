class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        bool p = false;
        int n = nums.size();
        for(int i =n-1;i>=2;i-=3){
            
            if((nums[i]-nums[i-1]>k)|| (nums[i-1]-nums[i-2]>k)||(nums[i]-nums[i-2]>k)){
                p = true;
                cout<<nums[i]<<" "<<nums[i-1]<<" "<<nums[i-2]<<endl;
                break;
            }

        }
        vector<vector<int>>ans(n/3);
        if(p)return {};
        int j = 0;
        for(int i = 0;i<n;i+=3){
            ans[j].push_back(nums[i]);
            ans[j].push_back(nums[i+1]);
            ans[j].push_back(nums[i+2]);
            j++;
        }
        return ans;
    }
};