class Solution {
public:
    int minMaxDifference(int num) {
        string k = to_string(num);
        cout<<k<<" ";
        char a = 'p';
        for(int i= 0;i<k.size();i++){
            if(k[i]=='9' and a=='p')continue;
            if(a=='p'){
                a = k[i];
                cout<<a<<" ";
            }
            if(k[i]==a)k[i] = '9';
        }
        cout<<k<<" ";
        string r = to_string(num);
        char rr = r[0];
        //finding lowest term
        for(int i =0;i<r.size();i++){
            if(r[i]==rr)r[i] = '0';
        }
        cout<<r<<endl;
        int ans = stoi(k)-stoi(r);
        // for(int i = 0;i<k.size();i++){
        //     ans = ans*10+(k[i]-'0');
        // }
        return ans;
    }
};