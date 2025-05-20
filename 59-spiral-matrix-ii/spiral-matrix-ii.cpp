class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>vll(n,vector<int>(n));
        int vl = 1;
        int top =0,bottom = n-1,left=0,right=n-1;
        while(top<=bottom and left<=right){
            // lft-right
            for (int i = left; i <= right; i++) {
                vll[top][i] =vl ;
                vl++;
            }
            top++;
            // top - bottom
            for (int i = top; i <= bottom; i++) {
                vll[i][right]=vl;
                vl++;
            }
            right--;
            // right-left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    vll[bottom][i] = vl;vl++;
                }
                bottom--;
            }
            // bottom-top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    vll[i][left] = vl;vl++;
                }
                left++;
            }
        }
        return vll;
    }
};