class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> v;
        
        int n = nums.size();
        
        for(int i=0 ; i< n ; i++){
            mp[nums[i]] = i;
        }
            
        
        for(int i=0 ; i< n ; i++){
            
             int diff = target - nums[i];
            
            if(mp.find(diff) != mp.end() && mp[diff] != i){
                v.push_back(i);
                v.push_back(mp[diff]);
                break;
            }
        
        }
        return v;
        
        
       
    }
};