/*
 * LeetCode Problem 1911: Maximum Alternating Subsequence Sum
 * Link     : https://leetcode.com/problems/maximum-alternating-subsequence-sum
 * Tags     : Dynamic Programming, Greedy, Array
 * Companies: Quince
 * 
 * Time Complexity  : O(N), where N is the number of elements in nums
 * Space Complexity : O(N), for the DP table
 */

 #define ll long long
class Solution {
public:
    ll solve(int i, vector<int>&nums , bool flag , vector<vector<ll>>& dp){
        //flag == true means even
        int n=nums.size();
        if(i>=n)return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];

        ll take = solve(i+1 , nums , !flag ,dp) + ((flag == true)? nums[i] : -nums[i]);
        ll notake = solve(i+1 , nums , flag ,dp);
        return dp[i][flag]= max(take , notake);
    }

    long long maxAlternatingSum(vector<int>& nums){
        int n=nums.size();
        vector<vector<ll>>dp(n+1 , vector<ll>(2,-1));
        return solve(0 ,nums, true ,dp);
    }
};

