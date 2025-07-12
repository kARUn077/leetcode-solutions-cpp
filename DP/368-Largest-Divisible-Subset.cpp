/*
 * LeetCode Problem 368: Largest Divisible Subset
 * Link     : https://leetcode.com/problems/largest-divisible-subset
 * Tags     : Dynamic Programming, Sorting, LIS Variation
 * Companies: Google, Adobe, Amazon
 * 
 * Time Complexity  : O(N^2), where N is the number of elements in nums
 * Space Complexity : O(N), for dp and hash arrays
 */


 class Solution {
public:
    //same as print lis
    vector<int> largestDivisibleSubset(vector<int>& nums){
       
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int maxi=1;
        int lastindex = 0;
        vector<int> dp(n,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){

                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    hash[i]=j;
                }
            }

            if(maxi<dp[i]){
                maxi=dp[i];
                lastindex=i;
            }
        }

        vector<int>ans;
        ans.push_back(nums[lastindex]);

        while(hash[lastindex] != lastindex){
            lastindex = hash[lastindex];
            ans.push_back(nums[lastindex]);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};