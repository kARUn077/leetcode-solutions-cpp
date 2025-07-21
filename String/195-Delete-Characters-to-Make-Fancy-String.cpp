/*
 * LeetCode Problem 1957: Delete Characters to Make Fancy String
 * Link     : https://leetcode.com/problems/delete-characters-to-make-fancy-string
 * Tags     : String, Greedy
 * Companies: Wayfair
 * 
 * Time Complexity  : O(N), where N is the length of the input string
 * Space Complexity : O(N), for storing the resulting string
 */

 class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        ans+=s[0];
        int n=s.size();
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                if(cnt>=2){
                    continue;
                }
                else{
                    ans+=s[i];
                    cnt++;
                }
            }
            else{
                ans+=s[i];
                cnt=1;
            }
        }
        return ans;
    }
};