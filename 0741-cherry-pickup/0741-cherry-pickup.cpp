class Solution {
public:
    int n;
    int dp[51][51][51]; 

    int solve(vector<vector<int>>& grid, int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2; // derived

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || 
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        // reached end
        if (r1 == n-1 && c1 == n-1) return grid[r1][c1];

        if (dp[r1][c1][c2] != -1) return dp[r1][c1][c2];

        int cherries = grid[r1][c1];
        if (c1 != c2) cherries += grid[r2][c2];

        int best = max({
            solve(grid, r1+1, c1, c2),     // down, down
            solve(grid, r1, c1+1, c2+1),   // right, right
            solve(grid, r1+1, c1, c2+1),   // down, right
            solve(grid, r1, c1+1, c2)      // right, down
        });

        cherries += best;
        return dp[r1][c1][c2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(grid, 0, 0, 0);
        return max(ans, 0); // if negative → no cherries
    }
};
