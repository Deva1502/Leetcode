class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans =0;
        for(int i = low;i<=high;i++){
            int vl = i;
            string k = to_string(vl);
            if(k.size()%2==0){
                int vl1=0,vl2=0;
                for(int j = 0;j<k.size()/2;j++){
                    vl1+=k[j]-'0';
                }
                for(int j = k.size()/2;j<k.size();j++){
                    vl2+=k[j]-'0';
                }
                if(vl1==vl2)ans++;
            }
        }
        return ans;
    }
};