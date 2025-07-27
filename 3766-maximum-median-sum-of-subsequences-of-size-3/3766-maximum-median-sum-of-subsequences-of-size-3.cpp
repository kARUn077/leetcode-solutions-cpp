class Solution {
public:
    long long maximumMedianSum(vector<int>& v){
        int n=v.size();
        sort(v.begin(),v.end());
        if(n<=3)return v[1];

        long long ans=0;
        int i=n-2;
        for(int j=0;j<n/3;j++){
            ans+= v[i];
            i-=2;
        }

        return ans; 
    }
};