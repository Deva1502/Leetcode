class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();
        for(auto i:tokens){
           if(i!="/" and i!="*" and i!="+" and i!="-" ){
            st.push(stoi(i));
           }
           else{
           int a = st.top();
           st.pop();
           int b = st.top();
           st.pop();
           if(i=="/")st.push(b/a);
           if(i=="+")st.push(a+b);
           if(i=="-")st.push(b-a);
           if (i=="*")st.push(a*b);}
        }
        return st.top();
    }
};