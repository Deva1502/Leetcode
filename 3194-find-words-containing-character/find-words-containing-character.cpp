class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int c=0, n = words.size();
        for(int i = 0;i<n;i++){
            string s = words[i];
            if(find(s.begin(),s.end(),x)!=s.end())ans.push_back(c);
            c++;
        }
        return ans;
    }
};