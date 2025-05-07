class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(),m = moveTime[0].size();
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        //-->{currtime,currrow,currcol}
        vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        pq.push({0,0,0});
        moveTime[0][0] = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int currtime = curr[0];
            int currrow=curr[1];
            int currcol=curr[2];
            if(currtime>=vis[currrow][currcol])continue;
            if(currrow==n-1 and currcol==m-1)return currtime;
            vis[currrow][currcol] = currtime;

            //move in all direction
            for(auto i:dir){
                int nxtr  = i[0]+currrow;
                int nxtcl = i[1]+currcol;
                if(nxtr>=0 and nxtr<n and nxtcl>=0 and nxtcl<m and vis[nxtr][nxtcl]==INT_MAX){
                    int nextt = max(moveTime[nxtr][nxtcl],currtime)+1;
                    pq.push({nextt,nxtr,nxtcl});
                }
            }
        }
        return -1;

    }
};