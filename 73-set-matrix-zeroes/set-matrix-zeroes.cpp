class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        vector<int>vl(n,0),vll(m,0);
        for(int i =0;i<n;i++){
           for(int j = 0;j<m;j++){
            if(matrix[i][j]==0){
                vl[i] = -1;
                vll[j] = -1;
            }
           }
        }
        for(int i =0;i<n;i++){
           for(int j = 0;j<m;j++){
            if(vl[i]==-1)matrix[i][j] = 0;
            if(vll[j]==-1)matrix[i][j] = 0;
           }
        }
    }
};