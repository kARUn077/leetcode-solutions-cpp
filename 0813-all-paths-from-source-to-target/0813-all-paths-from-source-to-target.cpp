class Solution {
public:
    void dfs(int node,int target ,vector<vector<int>>& ans, vector<vector<int>>& graph , vector<int>& temp){
        temp.push_back(node);

        if(node==target){
            ans.push_back(temp);
        }
        else{
            for(auto &it:graph[node]){
                dfs(it,target,ans ,graph,temp);
            }
        }

        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> ans;
        vector<int>temp;

        dfs(0,n-1 ,ans ,graph ,temp);
        return ans;
        
    }
};