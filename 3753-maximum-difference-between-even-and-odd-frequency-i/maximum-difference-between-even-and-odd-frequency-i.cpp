class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        for(auto i :s)mp[i]++;
        int vl = INT_MAX,vl1 = INT_MIN;
        for(auto i :mp){
            if(i.second%2)vl1  = max(vl1,i.second);
            else vl = min(vl,i.second);

        }
        return vl1-vl;
    }
};