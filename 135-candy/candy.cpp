class Solution {
public:
    int candy(vector<int>& ratings) {
            int n = ratings.size();
            vector<int>cand(n,1);
            for(int i =1;i<n;i++){
               if(ratings[i]>ratings[i-1])
               cand[i] = cand[i-1]+1;
            }            
            int ans=0;
            for(int i = n-1;i>0;i--){
                if(ratings[i-1]>ratings[i]){
                    cand[i-1] = max(cand[i]+1,cand[i-1]);
                }
                    ans += cand[i-1];

            }
            return ans + cand[n-1];
    }
};