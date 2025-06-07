class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                if (low > 0) low--;
                high--;
            } else { // c == '*'
                if (low > 0) low--; // treat * as )
                high++;             // or treat * as (
            }
            if (high < 0) return false; // too many ')'
        }
        return low == 0; // all opens can be matched
    }
};
