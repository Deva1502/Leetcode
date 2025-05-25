class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;
        if(n<=k)cost+=0;
        if(m<=k)cost+=0;
        long long vl1=0,vl2=0;
        if(n>k)vl1 =(long long) (n-k)*k;
        if(m>k)vl2 =(long long) (m-k)*k;
        return cost+vl1+vl2;
    }
};