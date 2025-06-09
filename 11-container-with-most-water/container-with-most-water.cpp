class Solution {
public:
    int maxArea(vector<int>& h) {
        int i = 0, j = h.size() - 1;
        int ans = 0;
        while (i < j) {
            int width = j - i;
            int height = min(h[i], h[j]);
            ans = max(ans, width * height);

            if (h[i] < h[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};
