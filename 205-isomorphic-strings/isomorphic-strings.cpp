class Solution {
public:
    bool solve(string s,string t){
        unordered_map<char,char>mp;
        for(int i = 0;i<s.size();i++){
            if(!mp[s[i]])mp[s[i]] = t[i];
            else{
                if (mp[s[i]]!=t[i])return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())return false;
        
        return solve(s,t) and solve(t,s);
    }
};