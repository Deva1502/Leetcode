class Solution {
public:
    /*
        this problem will be solved by bfs here i have to mailly do brute force 
        for ex we take a char count wheater that string exist atleat k time in given string and we push that string in queue such that we shoulod not always search for all possible subsequence we do to only traverse only on selected string again in that we add a char b/w a-z and search again and apart from this will also store max laxico. string in ans and last return that ans;     
    */
    bool ck(string k,string s,int c){
        int i = 0;
        int cnt = 0;
        for(int j =0;j<s.size();j++){
            if(s[j]==k[i]){
                i++;
                if(i==k.size()){
                    i = 0;
                    cnt++;
                    if(cnt==c)return true;
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int c) {
        // return "";
        queue<string>q;
        q.push("");
        string ans = "";
        //bfs
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            for(char j = 'a';j<='z';j++){
                string k = i+j;
                if(ck(k,s,c)){
                    ans = k;
                    q.push(k);
                }
                // ans = max(ans,k);
            }
        }
        return ans;
    }
};