class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        // max heap
        priority_queue<int> avail;
        // min heap
        priority_queue<int, vector<int>, greater<int>> asign;
        int cnt = 0;
        for (int i = 0, k = 0; i < nums.size(); i++) {
            // remove old queries
            while (!asign.empty() && asign.top() < i) {
                asign.pop();
            }
            while (k < queries.size() && queries[k][0] <= i) {
                // add new queries
                avail.push(queries[k++][1]);
            }
            // assign queries greedly
            while (asign.size() < nums[i] && !avail.empty() && avail.top() >= i)
 {

                asign.push(avail.top());
                avail.pop();
                cnt++;
            }
            if (asign.size() < nums[i])
                return -1;
        }
        return queries.size() - cnt;
    }
};