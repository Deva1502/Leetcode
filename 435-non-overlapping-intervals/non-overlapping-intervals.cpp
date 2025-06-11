class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), m = intervals[0].size();
        int ans = 0;
        vector<pair<int, int>> a;
        for (auto i : intervals) {
            a.push_back({i[0], i[1]});
        }
        sort(a.begin(), a.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });
        int p = a[0].first, q = a[0].second;
        for (int i = 1; i < n; i++) {
            if (a[i].first >= q)
                q = a[i].second;
            else {
                ans++;
            }
        }
        return ans;
    }
};