#define ll long long
class Solution {
public:
    ll solve(int i,int days ,vector<int>& v, vector<vector<int>>& dp){
        int n=v.size();
        //base case
        if(days==0 && i==n) return 0;
        if(days==0 || i==n ) return INT_MAX;  //not possible
        if(days > n-i) return INT_MAX;   //not possible

        if(dp[i][days] != -1) return dp[i][days];
    
        ll ans=INT_MAX;
        ll maxi=0;
        for(int ind=i ;ind<=n-days ;ind++){
            maxi=max(maxi ,1LL*v[ind]);
            ans = min(ans , maxi + solve(ind+1 ,days-1 ,v ,dp));
        }

        return dp[i][days]=ans;
    }

    int minDifficulty(vector<int>& v, int d){
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(d+1 ,-1));
        int ans= solve(0,d,v,dp);
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};