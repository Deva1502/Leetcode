class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>a;
        for(auto i:nums){
            a.push_back(to_string(i));
        }
        sort(a.begin(),a.end(),[](string a,string b){return a+b>b+a;});
        string ans = "";
        if(a[0]=="0")return "0";
        for(auto i:a){
            ans+=i;
        }
        return ans;
    }
};