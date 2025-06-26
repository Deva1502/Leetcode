class Solution {
public:
    int longestSubsequence(string s, int k) {
        int c0 = count(s.begin(),s.end(),'0');
        cout<<c0<<" ";
        int ans = 0;
        int n = s.size();
        long long sm = 0,c = 0;
        for(int i = n-1;i>=0;i--){
            if(s[i]=='1' and c<=32){
                if(sm+(1ll<<c)<=k){
                    sm+=(1<<c);
                    ans++;
                }
            }
            c++;
        }
        cout<<ans;
        return ans+c0;
    }
};