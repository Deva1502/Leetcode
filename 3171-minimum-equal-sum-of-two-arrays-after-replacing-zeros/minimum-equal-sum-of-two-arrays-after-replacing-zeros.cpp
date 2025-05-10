class Solution {
public:

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long c1=count(nums1.begin(),nums1.end(),0);
        long long c2=count(nums2.begin(),nums2.end(),0);
        cout<<c1<<" "<<c2<<endl;
        long long s1 = accumulate(nums1.begin(),nums1.end(),0ll);
        long long s2 = accumulate(nums2.begin(),nums2.end(),0ll);
        cout<<s1+c1<<" "<<s2+c2;
        if(s1!=s2 and c1==0 and c2==0)return -1;
        if(c1!=0 and c2 !=0){
            return max(s1+c1,s2+c2);

        }
        if(c1==0){
            if(s1<s2+c2)return -1;
            else return s1;
        }

        if(s2<s1+c1)return -1;
        return s2;

    }
};