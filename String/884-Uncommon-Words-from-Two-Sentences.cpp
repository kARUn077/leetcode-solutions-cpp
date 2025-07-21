/*
 * LeetCode Problem 884: Uncommon Words from Two Sentences
 * Link     : https://leetcode.com/problems/uncommon-words-from-two-sentences
 * Tags     : Hash Table, String, Counting
 * Companies: Amazon, Google, Microsoft, Expedia, Facebook
 * 
 * Time Complexity  : O(N + M), where N and M are lengths of the two input strings
 * Space Complexity : O(N + M), for storing words and their frequencies
 */

 class Solution {
public:
    vector<string> getTokens(string s){
        stringstream ss(s);
        string token = "";
        vector<string> tokens;

        while(getline(ss, token, ' ')){
            if(!token.empty()) tokens.push_back(token);
        }

        return tokens;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v1 = getTokens(s1);
        vector<string> v2 = getTokens(s2);

        unordered_map<string,int>mpp;
    
        int n=v1.size() , m=v2.size();
        for(int i=0;i<n;i++){
            mpp[v1[i]]++;
        }
        for(int i=0;i<m;i++){
            mpp[v2[i]]++;
        }

        vector<string>ans;

        for(auto &it:mpp){
            if(it.second==1)ans.push_back(it.first);
        }

        return ans;
    }
};