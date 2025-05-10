class Solution {
public:
int vl=0;
void solve(vector<vector<int>>&ans,int rst,int ren,int clst,int clen){
    int size=ren-rst;
    if(size==1){
        ans[rst][clst]=vl++;
        return;
    }
    int mdr=rst+size/2,mdc=clst+size/2;
    solve(ans,rst,mdr,mdc,clen);//top right
    solve(ans,mdr,ren,mdc,clen);//bottom right
    solve(ans,mdr,ren,clst,mdc);//bottom left
    solve(ans,rst,mdr,clst,mdc);//bottom left
}
    vector<vector<int>> specialGrid(int n) {
        int k =1<<n;
        vector<vector<int>>ans(k,vector<int>(k));
        solve(ans,0,k,0,k);

        return ans;
    }
};