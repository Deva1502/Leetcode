class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        int c = 0,cnt=0;
        for(auto i:mp){
            if(i.second%2==0)cnt+=i.second;
            else{
                cnt += i.second-1;
                c++;
            }
        }

        return (c>0)?cnt+1:cnt;
    }
};