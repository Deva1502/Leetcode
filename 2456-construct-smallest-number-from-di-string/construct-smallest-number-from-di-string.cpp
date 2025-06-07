class Solution {
public:
bool check (string p,string s){
    for(int i = 0;i<s.size();i++){
        if(s[i]=='I'){
            if(p[i]>=p[i+1])return false;
        }
        else{
            if(p[i]<p[i+1])return false;
        }
    }
    return true;
}
    string smallestNumber(string pattern) {
        int n = pattern.size();
        int inc = count(pattern.begin(), pattern.end(), 'I');
        int dec = n - inc;
        string per = "";
        for(int i = 1;i<=n+1;i++){
            per += (i+'0');
        }
        while(!check(per,pattern)){
            next_permutation(per.begin(),per.end());
        }
        return per;

    }
};