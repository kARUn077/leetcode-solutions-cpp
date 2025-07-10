/*
 * LeetCode Problem 174: Dungeon Game
 * Link     : https://leetcode.com/problems/dungeon-game
 * Tags     : Dynamic Programming, DP on Grid
 * Companies: Google, Uber, Amazon, Microsoft
 * 
 * Time Complexity: O(N × M)  // DP memoization over grid
 * Space Complexity: O(N × M) // for DP table
 */

 class Solution {
public:
    int dp[201][201];
    int solve(int i ,int j ,vector<vector<int>>& v){
        //base case
        int n=v.size();
        int m=v[0].size();

        if(i==n-1 && j==m-1){
            if(v[i][j]>0) return 1;
            else return abs(v[i][j])+1;
        }

        if(i>n-1 || j>m-1) return 1e9;

        if(dp[i][j] !=-1)return dp[i][j];

        int right = solve(i ,j+1 , v);
        int down = solve(i+1 ,j ,v);

        int need = min(right ,down)-v[i][j];
        //need<0 -> jitna chahiye , usse bohot jyada h
        //need>0 -> isse ek jyada toh chahiye

        return dp[i][j] = (need<=0) ? 1 : need;  
    }

    int calculateMinimumHP(vector<vector<int>>& v) {
        //binary search fail - tle

        int n=v.size();
        int m=v[0].size();
        memset(dp,-1 ,sizeof(dp));
        return solve(0,0,v);
    }
};
