class Solution {
public:
    /*
     approach: sorting, greedy, tree
            - the problem can be simplified by figuring out which nodes benefit
     having bits flipped (xor by k). as long as there is an even number of nodes
     where flip is beneficial to the sum, we want to flip them and pair them
     together. we can "pair" any nodes by bubbling the xors closer to the nodes
     where it is beneficial ie 1 - 2 - 3 if 1 and 3 benefit, xor (1,2) then
     (2,3) the second xor cancels out negative effect on node 2

                1 - 2 - 3 - 4
                if 1 and 4 benefit from xor
                    we can xor (1,2) then (3,4)
                    then we can xor (2,3) to negate the negative effects of xor
     2,3 initally

                1 - 2 - 3 -  4 - 5
                if 1 and 5 benefit from xor
                    we can xor (1,2) => (2,3) => (3,4) => (4,5)
                    by doing the above we have xored 1 and 5 once for the
     bemeficial change. and also xored all of 2,3,4 twice so that it remains the
     same

            - if we have one node that benefits from xoring and another where
     the negative impact is minimal (less than the benefit from xoring the other
     node) we want to xor these 2 nodes together bc we still come out ahead

            time: n * log(n)
            - need to sort array

            space: n
            - temporary space for sorting array
    */
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        // sorting the array nums based on how much the XOR with k decreases the
        // number
        sort(nums.begin(), nums.end(), [k](int a, int b) {
            int aXor = a ^ k;
            int bXor = b ^ k;
            return (bXor - b) < (aXor - a); // descending order of change
        });
        long long sm = 0, n = nums.size();
        for (int i = 0; i < n; i += 2) {
            if (i == n - 1) {
                sm += nums[i];
                continue;
            }
            int a = nums[i], b = nums[i + 1];
            int axor = a ^ k;
            int bxor = b ^ k;
            int vl = (axor - a) + (bxor - b);
            if (vl < 0)
                sm += a + b;
            else
                sm += axor + bxor;
        }
        return sm;
    }
};