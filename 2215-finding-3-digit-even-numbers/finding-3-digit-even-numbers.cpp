// class Solution {
// public:
//     vector<int> findEvenNumbers(vector<int>& a) {
//         vector<int> ans;
//         int n = a.size();
//         set<int> s;
//         for (int i = 0; i < n; i++) {
//             if (a[i] == 0) continue;
//             for (int j = 0; j < n; j++) {
//                 if (j == i) continue;
//                 for (int k = 0; k < n; k++) {
//                     if (k == i || k == j) continue;
//                     int num = a[i]*100 + a[j]*10 + a[k];
//                     if (num % 2 == 0) s.insert(num);
//                 }
//             }
//         }
//         for (int num : s) ans.push_back(num);
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& a) {
        vector<int> ans;
        int freq[10] = {0};
        
        // Count digit frequencies
        for (int d : a) freq[d]++;
        
        // Check all 3-digit even numbers
        for (int num = 100; num <= 999; num += 2) {
            int x = num;
            int tempFreq[10] = {0};
            tempFreq[x % 10]++; x /= 10;
            tempFreq[x % 10]++; x /= 10;
            tempFreq[x]++;
            
            bool valid = true;
            for (int d = 0; d < 10; d++) {
                if (tempFreq[d] > freq[d]) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans.push_back(num);
        }
        
        return ans;
    }
};
