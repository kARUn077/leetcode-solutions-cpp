/*
 * LeetCode Problem 3578: Count Partitions With Max-Min Difference at Most K
 * Link     : https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k
 * Tags     : Dynamic Programming, Prefix Sum, Sliding Window, Multiset
 * Companies: [To be updated]
 * 
 * Time Complexity : O(N log N)  // due to multiset insert/erase inside loop
 * Space Complexity: O(N)        // for DP and prefix arrays
 */

 class Solution {
public:
    int mod = 1e9+7;
    int countPartitions(vector<int>& nums, int k){
        int n=nums.size();
        vector<int> dp(n+1 , 0);
        vector<int> prev(n+1 , 0);

        dp[0]=1;
        prev[0]=1;

        int l=0;
        multiset<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);

            while(*st.rbegin() - *st.begin() > k){
                st.erase(st.find(nums[l]));
                l++;
            }

            // dp[i+1] = sum(dp[left..i])
            long long total = prev[i] - (l-1>=0 ? prev[l-1] : 0);
            dp[i+1] = (total+mod)%mod;
            prev[i+1] = (prev[i] + dp[i+1])%mod;
        }
        return dp[n];
    }
};