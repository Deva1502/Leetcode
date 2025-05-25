class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (string& w : words) {
            mp[w]++;
        }

        int ans = 0;
        int vl = 0;

        for (auto& [word, count] : mp) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word == rev) {
                int pairs = count / 2;
                ans += pairs * 4;
                mp[word] -= pairs * 2;
                if (mp[word] > 0) vl = 2;
            } else if (mp.find(rev) != mp.end()) {
                int pairs = min(mp[word], mp[rev]);
                ans += pairs * 4;
                mp[word] -= pairs;
                mp[rev] -= pairs;
            }
        }

        return ans + vl;
    }
};
