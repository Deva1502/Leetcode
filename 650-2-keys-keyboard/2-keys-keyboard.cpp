class Solution {
public:
    int minSteps(int n) {
        if(n==1)return 0;
        int vl = 2;
        int ans=0;
        while(n>1){
            while(n%vl==0){
                ans += vl;
                n/=vl;
            }
            vl++;
        }
        return ans;
    }
};