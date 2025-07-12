// /*
//  * LeetCode Problem 1420: Build Array Where You Can Find The Maximum Exactly K Comparisons
//  * Link     : https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons
//  * Tags     : Dynamic Programming, Memoization, Combinatorics
//  * Companies: Dunzo
//  * 
//  * Time Complexity  : O(N × M × K), where N = array length, M = max element, K = comparisons
//  * Space Complexity : O(N × M × K), for 3D DP table
//  */

//  #define mod 1000000007
// class Solution {
// public:

//     int dp[51][102][51];
//     int solve(int index, int b, int c, int n ,int m, int k){
//         //base case
//         if(index==n){
//             if(c==k)return 1;
//             else return 0;
//         }

//         if(dp[index][b+1][c] !=-1)return dp[index][b+1][c];
//         int ans=0;

//         for(int num=1; num<=m; num++){
//             if(num>b) ans = (ans + solve(index+1 , num , c+1 , n, m ,k))%mod;
//             else ans = (ans + solve(index+1 , b, c ,n , m ,k))%mod; 
//         }

//         ans = ans%mod;
//         return dp[index][b+1][c]=ans;

//     }

//     int numOfArrays(int n, int m, int k){
//         if(k>m) return 0;
//         //i , b , c
//         memset(dp, -1, sizeof(dp));
//         return solve(0, -1, 0, n, m, k);
//     }
// };