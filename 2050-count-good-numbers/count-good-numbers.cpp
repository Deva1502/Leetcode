class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long ll;

    ll power(ll base, ll exp) {
        ll result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(ll n) {
        ll even_positions = (n + 1) / 2;
        ll odd_positions = n / 2;

        ll even_choices = power(5, even_positions); // 0,2,4,6,8 (5 choices)
        ll odd_choices = power(4, odd_positions);   // 2,3,5,7 (4 choices)

        return (even_choices * odd_choices) % mod;
    }
};
