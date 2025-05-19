class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0],b=nums[1],c=nums[2];
        if(a+b<=c or b+c<=a or a+c<=b)return "none";
        return (a==b and b==c)?"equilateral":(a!=b and b!=c and c!=a)?"scalene":"isosceles";
    }
};