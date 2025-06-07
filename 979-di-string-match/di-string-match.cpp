class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int>a(n+1);
        int vl = n;
        int vll = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='I'){
                a[i] = vll;
                vll++;
            }
            else{
                a[i] = vl;
                cout<<vl<<" ";
                vl--;
            }
        }
        a[n] = vl;
        return a;


    }
};