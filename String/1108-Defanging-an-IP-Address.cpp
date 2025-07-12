/*
 * LeetCode Problem 1108: Defanging an IP Address
 * Link     : https://leetcode.com/problems/defanging-an-ip-address
 * Tags     : String, Parsing
 * Companies: Amazon, Apple, Google, Yahoo, Adobe,Facebook
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

        while (getline(ss, token, '.')) {
            if (!token.empty()) tokens.push_back(token);
        }

        return tokens;
    }

    string defangIPaddr(string s){
        vector<string> v = getTokens(s);
        string ans="";

        for(int i=0;i<v.size();i++){
            ans += v[i];
            if(i != v.size()-1) ans += "[.]";
        }
        return ans;
    }
};