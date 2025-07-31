#define ll long long
class Solution {
public:
    long long minimumSteps(string s){
        ll n=s.size();
        int total=n-1;
        ll ans=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                ans += total-i;
                total--;
            }
        }
        return ans;
    }
};