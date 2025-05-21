class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans  = 0;
        int n = columnTitle.size()-1;
        for(auto i:columnTitle){
            int vl = i- 'A'+1;
            // if(vl>1) 
            ans += vl*pow(26,n);
            n--;
        }
        return ans;
        // return 'z'-'a';

    }
};