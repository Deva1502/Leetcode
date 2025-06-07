class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0,c10=0,c20 = 0;
        for(int i = 0;i<bills.size();i++){
            if(bills[i]==5)c5++;
            if(bills[i]==10){
                if(c5==0)return false;
                c10++;
                c5--;
            }
            if(bills[i]==20){
                if(c5==0)return false;
                if(c10>0){
                    c10--;
                    c5--;
                }
                else{
                    if (c5<3)return false;
                    c5 -= 3;
                }
            }
        }
        return true;
    }
};