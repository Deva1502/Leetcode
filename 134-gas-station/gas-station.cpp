class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    long long total = 0;
    int i = 0;

    while (i < n) {
        int start = i;
        long long tank = 0;
        int cnt = 0;

        while (cnt < n) {
            int idx = (start + cnt) % n;
            tank += gas[idx] - cost[idx];
            if (tank < 0) break;
            cnt++;
        }

        if (cnt == n) return start;
        else i = start + cnt + 1;
    }

    return -1;
}

};