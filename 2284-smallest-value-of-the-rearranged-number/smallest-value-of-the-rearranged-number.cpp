class Solution {
public:
    void solve(long long n, vector<int>& c, int& vll) {
        while (n > 0) {
            int vl = n % 10;
            if (vl != 0) vll = min(vll, vl);
            c[vl]++;
            n /= 10;
        }
    }

    long long smallestNumber(long long num) {
        if (num == 0) return 0;

//postive case ka alag tareeke se solve karene negative ko alag
        if (num > 0) { // Positive Number
            vector<int> c(10, 0);
            int vll = 10;

            solve(num, c, vll);

            long long ans = vll;
            c[vll]--;

            for (int i = 0; i <= 9; i++) {
                while (c[i] > 0) {
                    ans = ans * 10 + i;
                    c[i]--;
                }
            }

            return ans;
        } else { // Negative Number: arrange in decreasing order
            num = -num;
            vector<int> c(10, 0);
            while (num > 0) {
                int vl = num % 10;
                c[vl]++;
                num /= 10;
            }

            long long ans = 0;
            for (int i = 9; i >= 0; i--) {
                while (c[i] > 0) {
                    ans = ans * 10 + i;
                    c[i]--;
                }
            }

            return -ans;
        }
    }
};
