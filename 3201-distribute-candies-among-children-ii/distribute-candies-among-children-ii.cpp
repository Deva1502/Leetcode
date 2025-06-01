class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i = 0;i<=min(limit,n);i++){
            int vl = max(min(limit,n-i)-max(0,n-i-limit)+1,0);
            ans+=vl;
        }
        return ans;
    }
};