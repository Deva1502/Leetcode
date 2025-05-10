class Solution {
public:
    int maxProduct(int n) {
        multiset<int> st;
        string s = to_string(n);
        for (auto i : s) {
            st.insert(i - '0');
        }
        auto it = st.rbegin();
        int x = *it;
        ++it;
        int y = *it;

        return x * y;
    }
};
