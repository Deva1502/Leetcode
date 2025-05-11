class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        if(mp.size()<=k)return 0;
        int vl=mp.size()-k;
        vector<int>st;
        for(auto i:mp){
            st .push_back(i.second);
        }
        sort(st.begin(),st.end());
        int ans=0;
        for(auto i:st){
            if(vl>0){
                ans+=i;
                vl--;
            }
        }
        return ans;
    }
};