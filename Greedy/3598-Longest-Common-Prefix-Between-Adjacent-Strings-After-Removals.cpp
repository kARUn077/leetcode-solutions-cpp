/*
 * LeetCode Problem 3598: Longest Common Prefix After Deleting One Word
 * Link     : https://leetcode.com/problems/longest-common-prefix-after-deleting-one-word
 * Tags     : String, Prefix, Greedy, Precomputation
 * Companies: [To be updated]
 * 
 * Time Complexity  : O(N * M), where N = number of words and M = average word length
 * Space Complexity : O(N), for prefix/suffix LCP arrays
 */

 class Solution {
public:
    int commonPrefixLength(const string& a, const string& b) {
        int len = 0;
        while (len < a.size() && len < b.size() && a[len] == b[len]) len++;
        return len;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        if (n == 1) return {0};

        vector<int> lcp(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            lcp[i] = commonPrefixLength(words[i], words[i + 1]);
        }

        // prefix max of lcp
        vector<int> prefix(n - 1), suffix(n - 1);
        prefix[0] = lcp[0];
        for (int i = 1; i < n - 1; ++i)
            prefix[i] = max(prefix[i - 1], lcp[i]);

        suffix[n - 2] = lcp[n - 2];
        for (int i = n - 3; i >= 0; --i)
            suffix[i] = max(suffix[i + 1], lcp[i]);

        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            int maxLCP = 0;
            if (i > 0 && i < n - 1) {
                maxLCP = commonPrefixLength(words[i - 1], words[i + 1]);
                if (i - 2 >= 0)
                    maxLCP = max(maxLCP, prefix[i - 2]);
                if (i + 1 < n - 1)
                    maxLCP = max(maxLCP, suffix[i + 1]);
            } else if (i == 0) {
                if (n > 2)
                    maxLCP = suffix[1];
            } else if (i == n - 1) {
                if (n > 2)
                    maxLCP = prefix[n - 3];
            }
            ans[i] = maxLCP;
        }

        return ans;
    }
};