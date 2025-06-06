class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;

        vector<bool> visited(26, false);
        string result = "";

        for (char ch : s) {
            freq[ch]--;

            if (visited[ch - 'a']) continue;

            while (!result.empty() && ch < result.back() && freq[result.back()] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return result;
    }
};
