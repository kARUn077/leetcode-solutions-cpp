/*
 * LeetCode Problem 3587: Minimum Number of Swaps to Make the Binary Array Alternating
 * Link     : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-array-alternating
 * Tags     : Greedy, Array, Math
 * Companies: [To be updated]
 * 
 * Time Complexity  : O(N), where N is the size of the array
 * Space Complexity : O(N), for storing the positions of odd and even elements
 */

 class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                even++;
            else
                odd++;
        }

        vector<int> oddpos, evenpos;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                evenpos.push_back(i);
            else
                oddpos.push_back(i);
        }

        if (abs(odd - even) > 1)
            return -1;
        if (n % 2 == 0) {
            int ans1 = 0, ans2 = 0;
            int ind = 0;

            for (int i = 0; i < evenpos.size(); i++) {
                ans1 += abs(evenpos[i] - ind);
                ind += 2;
            }

            ind = 0;

            for (int i = 0; i < oddpos.size(); i++) {
                ans2 += abs(oddpos[i] - ind);
                ind += 2;
            }

            return min(ans1, ans2);
        }

        int ans = 0;
        int ind = 0;
        if (odd > even) {
            for (int i = 0; i < oddpos.size(); i++) {
                ans += abs(oddpos[i] - ind);
                ind += 2;
            }
            return ans;
        }

        else {
            for (int i = 0; i < evenpos.size(); i++) {
                ans += abs(evenpos[i] - ind);
                ind += 2;
            }
        }
        return ans;
    }
};