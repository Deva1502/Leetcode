class Solution {
public:
    string answerString(string s, int numFriends) {
        int i = 0, j = 0;
        if(numFriends==1)return s;
        vector<int>st;
        char vl = *max_element(s.begin(),s.end());
        for(int i = 0;i<s.size();i++){
            if(vl==s[i])st.push_back(i);
        }
        string ans="";
        int ele = s.size()-numFriends+1;
        for(auto i:st){
            string k =(ele<s.size()-i)?s.substr(i,ele):s.substr(i,s.size());
            ans = max(ans,k);
        }
        return ans;
    }
};