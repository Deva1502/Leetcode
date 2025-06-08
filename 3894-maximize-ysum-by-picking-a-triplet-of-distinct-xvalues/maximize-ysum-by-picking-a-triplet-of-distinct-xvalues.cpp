class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = size(x);
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++){
            if(mp[x[i]])mp[x[i]] = max(mp[x[i]],y[i]);
            else mp[x[i]] = y[i];
        }
        vector<int>vl;
        for(auto i:mp){
            vl.push_back(i.second);
        }
        sort(vl.begin(),vl.end(),greater<int>());
        if(vl.size()<3)return -1;
        return vl[0]+vl[1]+vl[2];
    }
};