class Solution {
public:
typedef __int128 ll;
    bool solve(vector<int>& a, ll target, int i, ll vl) {
        if (target == vl) return true;
        if (vl > target) return false;
        if (i >= a.size()) return false;
        
        // Only proceed with multiplication if it won't overflow
        if (vl <= target / a[i]) {
            if (solve(a, target, i + 1, a[i] * vl)) return true;
        }
        
        return solve(a, target, i + 1, vl);
    }

    bool checkEqualPartitions(vector<int>& nums, ll target) {
        ll vl = 1;
        for (auto i : nums) {
            vl *= i;
        }
        if ((vl) != target*target) return false;
        return solve(nums, target, 0, 1LL);
    }
};
