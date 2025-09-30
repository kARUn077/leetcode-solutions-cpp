class Solution {
public:
    vector<vector<int>> generate(int n){
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            ans[i] =  vector<int> (i+1 ,1);
            for(int k=1 ;k<i ; k++){
                ans[i][k] = ans[i-1][k] + ans[i-1][k-1];
            }

        }

        return ans;
    }
};