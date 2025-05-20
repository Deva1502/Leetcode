class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int>ans(size(num1)+size(num2),0);
        if(num1=="0" || num2=="0")return "0";
        //multiply udsing string multiplication
        for(int i =size(num1)-1;i>=0;i--){
           for(int j =size(num2)-1;j>=0;j--){
              ans[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
              ans[i+j]+=ans[i+j+1]/10;//carry
              ans[i+j+1]%=10;
           }
        }
        string vl="";
        int i = 0;
        while(ans[i]==0)i++;
        while(i<size(ans)){vl += to_string(ans[i]);i++;}
        return vl;
    }

};