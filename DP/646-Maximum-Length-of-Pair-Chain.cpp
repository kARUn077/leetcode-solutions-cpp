/*
 * LeetCode Problem 646: Maximum Length of Pair Chain
 * Link     : https://leetcode.com/problems/maximum-length-of-pair-chain
 * Tags     : Dynamic Programming, Greedy, Sorting
 * Companies: Amazon, Google, Siemens, Flipkart, Microsoft, Facebook, Inmobi, Citrix, Walmart, Uber, Capgemini, Cadence Design   Systems, Josh Technologies, Bloomberg

 * 
 * Time Complexity  : O(N^2), where N is the number of pairs
 * Space Complexity : O(N^2), for the DP table
 */

 class Solution {
public:
    int solve(int i , vector<vector<int>>& nums , int prev , vector<vector<int>>& dp){
        int n=nums.size();
        if(i>=n)return 0;
        if(dp[i][prev+1] !=-1) return dp[i][prev+1];

        int take=0;
        if(prev==-1 || nums[i][0]>nums[prev][1]) take = 1 + solve(i+1 , nums ,i ,dp);
        int notake = solve(i+1 , nums, prev ,dp);

        return dp[i][prev+1]= max(take , notake);
    }


    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin() , pairs.end());
        vector<vector<int>> dp(n+1 , vector<int>(n+2,-1));
        return solve(0 ,pairs , -1 ,dp);
    }
};