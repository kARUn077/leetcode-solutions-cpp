class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislike){
        vector<vector<int>> adj(n+1);

        for(auto &it:dislike){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        vector<int>color(n+1,-1);

        for(int i=1;i<=n;i++){
            if(color[i]!=-1)continue;

            queue<int>q;
            q.push(i);
            color[i]=1;

            while(!q.empty()){
                int sz=q.size();
                int temp=q.front();
                q.pop();

                for(int &v:adj[temp]){
                    if(color[v]==color[temp]) return false;
                    else if(color[v]==-1){
                        color[v]=!color[temp];
                        q.push(v);
                    }
                }
            }
        }

        return true;
    }
};