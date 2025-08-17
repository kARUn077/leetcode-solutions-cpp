class Solution {
public:
    int ans=0;
    bool dfs(int node, int parent ,vector<vector<int>>& adj, vector<bool>& hasApple){
        bool has=hasApple[node];

        for(auto &child:adj[node]){
            if(child==parent) continue;

            if(dfs(child ,node,adj ,hasApple)){
                ans+=2;
                has=true;
            }
        }

        return has;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0 ,-1 ,adj ,hasApple);
        return ans;
    }
};