class Solution {
public:
    int differenceOfSums(int n, int m) {
        int vl = 0,vll=0;
        for(int i = 1;i<=n;i++){
            if(i%m==0)vl+=i;
            else vll+=i;
        }
        return vll-vl;
    }
};