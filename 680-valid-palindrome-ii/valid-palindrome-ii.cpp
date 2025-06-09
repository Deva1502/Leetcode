class Solution {
public:
    bool check(string s){
        string k = s;
        reverse(k.begin(), k.end());
        return s == k;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        while (i < j) { 
            if (s[i] != s[j]) {
                string s1 = s.substr(i + 1, j - i); // FIXED
                string s2 = s.substr(i, j - i);     // FIXED
                return check(s1) || check(s2);
            }
            i++;
            j--;
        }
        return true;
    }
};
