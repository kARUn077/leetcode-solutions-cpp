class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target){
        int n = v.size();
        int m = v[0].size();
        int i=0 ,j=m-1;
        while(i<n && j>=0){
            if(v[i][j] == target) return true;

            else if(v[i][j] > target){
                j--;
            }
            else i++;
        }

        return false;
        
    }
};