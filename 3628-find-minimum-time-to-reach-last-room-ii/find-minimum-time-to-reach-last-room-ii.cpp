class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // --> {currtime, currrow, currcol}
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currtime = curr[0], currrow = curr[1], currcol = curr[2];
            
            if (currtime >= vis[currrow][currcol]) continue;
            if (currrow == n - 1 && currcol == m - 1) return currtime;
            vis[currrow][currcol] = currtime;

            for (auto d : dir) {
                int nxtr = currrow + d[0];
                int nxtcl = currcol + d[1];

                if (nxtr >= 0 && nxtr < n && nxtcl >= 0 && nxtcl < m) {
                    int arrivalTime = max(moveTime[nxtr][nxtcl], currtime);
                    int cost = (currrow + currcol) % 2 + 1;
                    int totalTime = arrivalTime + cost;

                    if (totalTime < vis[nxtr][nxtcl]) {
                        pq.push({totalTime, nxtr, nxtcl});
                    }
                }
            }
        }
        return -1;
    }
};
