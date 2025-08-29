class Solution {
public:
    int dp[101][101][101];

    //max falling path sum
    int solve(int i,int j1 ,int j2 ,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        //base case
        if(i>=n || j1<0 || j1>=m || j2<0 || j2>=m){
            return -1e9;
        }

        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int ans=-1e9;
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                int val=0;

                if(j1==j2) val = grid[i][j1] + solve(i+1 ,j1+dj1 ,j2+dj2 ,grid);
                else val = grid[i][j1] + grid[i][j2] + solve(i+1 ,j1+dj1 ,j2+dj2 ,grid);

                ans = max(ans ,val);
            }
        }

        return dp[i][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        memset(dp,-1,sizeof(dp));

        return solve(0,0,m-1,grid);  //there is no need of 4 variables
    }
};