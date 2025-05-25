/**
 * @param {number} n
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var minCuttingCost = function(n, m, k) {
    let x = 0,y =0;
    if(n>k)x = (n-k)*k;
    if(m>k)y = (m-k)*k;
    return x+y;
};