class Solution {
public:
    /*We need to start considering elements from the leaf nodes. We have to leve
    at least one node in a path from parent to leave. At each root we have two
    options ( we will take the larger one ofcourse ) either take the root and
    leave the child nodes ( or already leftout nodes) or take the child nodes
    (or leftout values ) and leave the root node*/
    typedef long long ll;
    pair<ll,ll> solve(vector<vector<int>> &adj,vector<int>&arr,int node,int parent){
        ll lft = 0,tkn = 0;
        for(auto i:adj[node]){
            if(i==parent)continue;
            auto [t,l] = solve(adj,arr,i,node);
            tkn += t;lft += l;
        }
        tkn += (lft!=0)?max(lft,(ll)arr[node]):0;
        lft = (lft!=0)?min(lft,(ll)arr[node]):arr[node];

        return {tkn,lft};
    }
    ll maximumScoreAfterOperations(vector<vector<int>>& edges,
                                   vector<int>& values) {
        vector<vector<int>> adj(values.size());
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return solve(adj,values,0,-1).first;
    }
};