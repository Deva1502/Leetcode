class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target)return false;
        int vl = __gcd(x,y);
        if(target%vl==0)return true;
        return false;

    }
};