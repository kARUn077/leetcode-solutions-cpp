class Solution {
public:
    #define ll long long
    ll total=0;

    ll dfs(int u ,int v ,vector<vector<int>>& adj ,int maxSeats){
        ll cnt=1;

        for(auto &it: adj[u]){
            if(it==v) continue;

            ll child = dfs(it ,u ,adj ,maxSeats);
            total += (child + maxSeats - 1)/maxSeats;

            cnt += child;
        }

        return cnt;
    }

    long long minimumFuelCost(vector<vector<int>>& v, int seats){
        int n = v.size()+1;
        vector<vector<int>> adj(n);
        for(auto &it: v){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(0,-1,adj,seats);
        return total;
    }
};