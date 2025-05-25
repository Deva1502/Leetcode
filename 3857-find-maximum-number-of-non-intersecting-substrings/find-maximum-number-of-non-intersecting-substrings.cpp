class Solution {
public:
    int maxSubstrings(string word) {
        vector<int>ck(26,-1);
        int p= 0;
        int ans = 0;
        int n = word.size();
        for(int i =0;i<n;i++){
           if(ck[word[i]-'a']==-1){
            ck[word[i]-'a']=i;
           }
           else{
            int vl = ck[word[i]-'a'];
            if(i-vl+1>=4){
                cout<<vl<<" ";
                ans++;
                vector<int>pp(26,-1);
                ck = pp; 
            }
           }
        }
        return ans;
    }
};