class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr){
        int n=arr.size();
        set<int>prev,ans;
        for(int i=0;i<n;i++){
            set<int>curr;
            curr.insert(arr[i]);
            for(auto &it:prev){
                curr.insert(it | arr[i]);
            }
            
            prev=curr;
            for(auto &it:prev)ans.insert(it);
        }

        return ans.size();
    }
};