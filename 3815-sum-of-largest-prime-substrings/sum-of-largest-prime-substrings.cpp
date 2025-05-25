class Solution {
public:
    typedef long long ll;
    
    bool isPrime(ll num) {
        if (num <= 1)
            return false;
        if (num <= 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;
        for (ll i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }
    
    ll sumOfLargestPrimes(string s) {
        int n = s.size();
        vector<ll> vl;
        
        // Generate all possible substrings
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                ll num = stoll(sub);
                vl.push_back(num);
            }
        }
        
        // Remove duplicates and sort in descending order
        unordered_set<ll> seen;
        vector<ll> p;
        for (ll num : vl) {
            if (seen.find(num) == seen.end()) {
                seen.insert(num);
                p.push_back(num);
            }
        }
        
        sort(p.begin(), p.end(), greater<ll>());
        
        // Find the 3 largest primes
        ll sum = 0;
        int count = 0;
        for (ll num : p) {
            if (isPrime(num)) {
                sum += num;
                count++;
                if (count == 3)
                    break;
            }
        }
        
        return sum;
    }
};