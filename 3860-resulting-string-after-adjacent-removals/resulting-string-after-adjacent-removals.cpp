class Solution {
public:
    string resultingString(string s) {
        string stk;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (!stk.empty() and (fabs(stk.back() - s[i]) == 1 or fabs(stk.back() - s[i]) == 25))
                stk.pop_back();
            else
                stk.push_back(s[i]);
        }
        return stk;
    }
};