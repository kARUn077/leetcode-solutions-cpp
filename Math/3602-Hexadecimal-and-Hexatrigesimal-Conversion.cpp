/*
 * Problem: Hexadecimal and Hexatrigesimal Conversion
 * Tags    : Base Conversion, String Manipulation, Math
 * 
 * Time Complexity : O(log N)  // for converting n^2 and n^3 to base 16 and base 36
 * Space Complexity: O(log N)  // for storing characters of the converted number
 */

 #define ll long long
class Solution {
public:
    string solve(ll num ,ll base){
        string alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        vector<char>v;
        while(num>0){
            int rem=num%base;
            v.push_back(alpha[rem]);
            num/=base;
        }

        reverse(v.begin(),v.end());
        return string(v.begin(),v.end());
    }

    
    string concatHex36(int n) {
        ll n1=1LL*n*n;
        ll n2=1LL*n*n*n;

        string s1=solve(n1,16);
        string s2=solve(n2,36);

        string ans=s1+s2;
        return ans;
    }
};
