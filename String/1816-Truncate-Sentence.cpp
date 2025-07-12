/*
 * LeetCode Problem 1816: Truncate Sentence
 * Link     : https://leetcode.com/problems/truncate-sentence
 * Tags     : String, Parsing
 * Companies: Bloomberg
 * 
 * Time Complexity  : O(N), where N is the length of the input string
 * Space Complexity : O(N), for storing tokens and the result string
 */

 class Solution {
public:
    vector<string> getTokens(string s){
        stringstream ss(s);
        string token = "";
        vector<string> tokens;

        while (getline(ss, token, ' ')) {
            if (!token.empty()) tokens.push_back(token);
        }

        return tokens;
    }

    string truncateSentence(string s, int k){
        vector<string> v = getTokens(s);
        string ans;
        for(int i=0;i<k;i++){
            ans += v[i];
            if(i!=k-1) ans+= ' ';
        }
        
        return ans;
    }
};