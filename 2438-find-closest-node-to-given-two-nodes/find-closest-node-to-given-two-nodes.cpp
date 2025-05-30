class Solution {
public:
    void bfs(vector<vector<int>>&adj,vector<int>&dis,int start){
        int n = adj.size();
        queue<int>q;
        q.push(start);
        dis.assign(n,-1);//for vis also store dist
        dis[start]=0;
        while(!q.empty()){
            int vl = q.front();
            q.pop();
            for(auto i:adj[vl]){
                if(dis[i]==-1){
                    dis[i] = dis[vl]+1;
                    q.push(i);
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>>ad(n);
        for(int i = 0;i<n;i++){
            if(edges[i]!=-1){
                ad[i].push_back(edges[i]);
            }
        }
        vector<int>dis1(n,-1),dis2(n,-1);
        bfs(ad,dis1,node1);
        bfs(ad,dis2,node2);
        int res = -1;
        int vlll = INT_MAX;
        for(int i = 0;i<n;i++){
            if(dis1[i]!=-1 and dis2[i]!=-1){
                int vl = max(dis1[i],dis2[i]);
                if(vl<vlll){
                    vlll = vl;
                    res = i;
                }
            }
        }
        return res;
    }
};