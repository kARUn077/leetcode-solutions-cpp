/*
 * LeetCode Problem 1498: Number of Subsequences That Satisfy the Given Sum Condition
 * Link     : https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
 * Tags     : Two Pointers, Sorting, Binary Search, Greedy
 * Companies: Amazon, Google, ByteDance
 * 
 * Time Complexity: O(N log N)  // due to sorting
 * Space Complexity: O(N)       // for power-of-2 precomputation
 */

 class Solution {
public:
    int numSubseq(vector<int>& nums, int target){
        int MOD = 1e9+7;
        int n=nums.size();
        sort(nums.begin(), nums.end());

        // Precompute powers of 2
        vector<int>pow2(n, 1);
        for (int i=1;i<n;i++)
            pow2[i] = (pow2[i-1]*2LL)%MOD;

        int left=0, right=n-1;
        int ans=0;

        //because sequence ka formlua 2^(size)
        //and hum har baar min ko fix kar denge , toh bacha hua (size-1) mein se sequence nikalenge

        while(left<=right){
            if (nums[left] + nums[right] <= target) {
                ans = (ans + pow2[right-left])%MOD;
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};