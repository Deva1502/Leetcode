class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Build directed graph and calculate indegrees
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        // dp[i][c] = maximum count of color c ending at node i
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        
        // Initialize nodes with indegree 0
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        
        int processed = 0;
        int maxVal = 0;
        
        // Topological sort with DP
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;
            
            // Update maximum value
            for(int c = 0; c < 26; c++) {
                maxVal = max(maxVal, dp[node][c]);
            }
            
            // Process all neighbors
            for(int neighbor : adj[node]) {
                // Update DP values for neighbor
                for(int c = 0; c < 26; c++) {
                    if(c == colors[neighbor] - 'a') {
                        dp[neighbor][c] = max(dp[neighbor][c], dp[node][c] + 1);
                    } else {
                        dp[neighbor][c] = max(dp[neighbor][c], dp[node][c]);
                    }
                }
                
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Check for cycle
        if(processed != n) {
            return -1; // Cycle detected
        }
        
        return maxVal;
    }
};