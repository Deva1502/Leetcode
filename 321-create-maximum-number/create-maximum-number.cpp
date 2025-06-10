typedef long long ll;
#define pii pair<ll, ll>
#define vi vector<int>
#define si set<ll>
#define vvi vector<vector<ll>>
#define svi set<vector<ll>>
#define mii map<ll, ll>
#define setbits(x) __builtin_popcountll(x)
#define mp make_pair
#define all(a) a.begin(), a.end()
#define yes cout << 'yes' << endl
#define no cout << 'NO' << endl
#define zerobits(x) __builtin_ctzll(x)
#define f(i, a, b) for (long long i = a; i < b; i++)
#define rf(i, a, b) for (long long i = a; i >= b; i--)
class Solution {
    vi maxkEle(vi& a, int k) {
        const int n = a.size();
        vi vl;
        int remain = k;

        for (int i = 0; i < n; i++) {
            while (!vl.empty() && vl.back() < a[i] && vl.size() + (n - i - 1) >= k) {
                vl.pop_back();
            }
            if (vl.size() < k) {
                vl.push_back(a[i]);
            }
        }
        return vl;
    }

    vi merge(vi& v1, vi& v2) {
        vi ans;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (vi(v1.begin() + i, v1.end()) > vi(v2.begin() + j, v2.end())) {
                ans.push_back(v1[i++]);
            } 
            else {
                ans.push_back(v2[j++]);
            }
        }

        while (i < v1.size()) ans.push_back(v1[i++]);
        while (j < v2.size()) ans.push_back(v2[j++]);

        return ans;
    }

public:
    vi maxNumber(vi& nums1, vi& nums2, int k) {
        const int n = nums1.size(), m = nums2.size();
        vi ans;

        for (int i = max(0, k - m); i <= min(k, n); i++) {
            vi a = maxkEle(nums1, i);
            vi b = maxkEle(nums2, k - i);

            vi temp = merge(a, b);
            ans = max(ans, temp);
        }

        return ans;
    }
};
