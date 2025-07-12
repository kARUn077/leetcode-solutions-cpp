/*
 * LeetCode Problem 3592: Find the Value of the Hidden Array
 * Link     : https://leetcode.com/problems/find-the-value-of-the-hidden-array
 * Tags     : Dynamic Programming, Coin Change, Constructive Algorithms
 * Companies: [To be updated]
 * 
 * Time Complexity  : O(N² × M), where N is input size and M is target amount
 * Space Complexity : O(N × M), for DP table
 */

 class Solution {
public:
    int solve(int i , vector<int>&coins , int amt , vector<vector<int>> &dp){
        //base case
        int n=coins.size();
        if(amt==0)return 1;
        if(i>=n)return 0;
        if(dp[i][amt] !=-1) return dp[i][amt];

        int take=0;
        if(amt-coins[i]>=0) take = solve(i , coins , amt-coins[i] ,dp);
        int notake = solve(i+1 , coins , amt , dp);
        return dp[i][amt] = take + notake;
    }

    vector<int> findCoins(vector<int>& v){
        //use coin change logic
        int n=v.size();
        vector<int> coins;

        for(int i=0;i<n;i++){
            int amt = i+1;
            vector<vector<int>> dp(coins.size()+1 ,vector<int>(amt+1, -1));
            //it like , no. of ways , to make amt=20 using coins=[2 , 3 , 4 , 5];

            int ways = solve(0 , coins , amt , dp);
            if(ways == v[i]) continue;
            if(ways == v[i]-1) coins.push_back(i+1);
            else return {};
        }

        return coins;
    }
};