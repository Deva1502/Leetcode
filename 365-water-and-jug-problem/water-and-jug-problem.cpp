class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (x + y < target) return false;
        if (x == target || y == target || x + y == target) return true;

        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto [a, b] = q.front(); q.pop();
            if (a + b == target) return true;
            if (visited.count({a, b})) continue;
            visited.insert({a, b});

            // all possible states
            q.push({x, b});           // fill jug X
            q.push({a, y});           // fill jug Y
            q.push({0, b});           // empty jug X
            q.push({a, 0});           // empty jug Y

            // pour X -> Y
            int pourXY = min(a, y - b);
            q.push({a - pourXY, b + pourXY});

            // pour Y -> X
            int pourYX = min(b, x - a);
            q.push({a + pourYX, b - pourYX});
        }

        return false;
    }
};
