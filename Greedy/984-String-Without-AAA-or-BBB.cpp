/*
 * LeetCode Problem 984: String Without AAA or BBB
 * Link     : https://leetcode.com/problems/string-without-aaa-or-bbb
 * Tags     : Greedy, String
 * Companies: Grab, Zalando
 * 
 * Time Complexity  : O(a + b), where a and b are the number of 'a's and 'b's
 * Space Complexity : O(1), excluding the output string
 */


class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        while(a>0 || b>0){
            if(a>b){
                if(a>=2){
                    ans += "aa";
                    a-=2;
                }else{
                    ans += 'a';
                    a--;
                }
                if(b>0){
                    ans += 'b';
                    b--;
                }
            }

            else if(a<b){
                if(b>=2){
                    ans += "bb";
                    b-=2;
                }else{    
                    ans += 'b';
                    b--;
                }
                if(a>0){
                    ans += 'a';
                    a--;
                }
            }

            else{
                ans+="ab";
                a-=1;
                b-=1;
            }
        }
        return ans;
    }
};