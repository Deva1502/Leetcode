class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int mn =0,mx =0,curr=0;
        for(auto i:differences){
            curr+=i;
            mn = min(mn,curr);
            mx = max(mx,curr);
            if(mx-mn>upper-lower)return 0;
        }
        return (upper-lower)- (mx-mn)+1;
    }
};