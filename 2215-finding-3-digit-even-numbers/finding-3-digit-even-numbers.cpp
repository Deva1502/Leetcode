class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& a) {
        vector<int> ans;
        int n = a.size();
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    int num = a[i]*100 + a[j]*10 + a[k];
                    if (num % 2 == 0) s.insert(num);
                }
            }
        }
        for (int num : s) ans.push_back(num);
        return ans;
    }
};
