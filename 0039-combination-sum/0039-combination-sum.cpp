class Solution {
public:

    void solve(int i, vector<int>& c, int target, vector<int>& ds, vector<vector<int>>& ans){
        int n=c.size();
        //base case
        if(i==n){
            if(target == 0){
                ans.push_back(ds);
                return;
            }
            else return;
        }


    }

    vector<vector<int>> combinationSum(vector<int>& c, int target){
        int n=c.size();

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, c, target, ds, ans);
        return ans;
    }
};