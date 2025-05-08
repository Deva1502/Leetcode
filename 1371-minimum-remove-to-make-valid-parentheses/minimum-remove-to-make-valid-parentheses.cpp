class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st1;
        int op = 0;
        for (char c : s) {
            if (c == '(') {
                op++;
                st1.push(c);
            } else if (c == ')') {
                if (op > 0) {
                    op--;
                    st1.push(c);
                }
            } else {
                st1.push(c);
            }
        }
        stack<char> st2;
        op = 0;
        while (!st1.empty()) {
            char c = st1.top(); st1.pop();
            if (c == ')') {
                op++;
                st2.push(c);
            } 
            else if (c == '(') {
                if (op > 0) {
                    op--;
                    st2.push(c);
                }
            } 
            else {
                st2.push(c);
            }
        }
        string ans;
        while (!st2.empty()) {
            ans += st2.top(); st2.pop();
        }

        return ans;
    }
};
