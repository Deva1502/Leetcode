class Solution {
public:
    int dist(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int maxDistance(string st, int k) {
        // N->y++;,W->x--,E->x++,S->y--
        int ans = 0;
        unordered_map<char, int> mp;
        int e = 0, w = 0, n = 0, s = 0;
        for (auto i : st) {
            if (i == 'E')
                e++;
            else if (i == 'W')
                w++;
            else if (i == 'N')
                n++;
            else
                s++;

            int x = min({e, w, k});
            int y = min({n, s, k - x});
            ans = max(ans, abs(n - s) + 2 * y + abs(e - w) + 2 * x);
        }

        // cout<<x<<" "<<y;

        return ans;
    }
};