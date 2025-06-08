class Solution {
public:
void solve(int i,vector<int>&st,int n){
    if(i>n)return;
    st.push_back(i);
    for(int j = 0;j<10;j++){
        int vl = i*10+j;
        if(vl<=n)solve(vl,st,n);
        else break;
    }

}
    vector<int> lexicalOrder(int n) {
        vector<int>st;
        //by thinking we can easily understand that this ques can be easily solved by dfs
        for(int i = 1;i<10;i++){
            solve(i,st,n);
        }
        return st;
    }
};