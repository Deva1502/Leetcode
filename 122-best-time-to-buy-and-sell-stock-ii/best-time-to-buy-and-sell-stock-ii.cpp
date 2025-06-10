class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, a = prices[0];
        for(int i = 1;i<prices.size();i++){
            if(prices[i]>a){
                ans+= (prices[i]-a);
            }
            a = prices[i];
        }
        return ans;
    }
};