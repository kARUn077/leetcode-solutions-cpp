class Solution {
public:
    int majorityElement(vector<int>& nums){
        int n=nums.size();
        //Boyer-Moore 
        
        int maj = -1;
        int cnt= 0;

        for(int i=0;i<n;i++){
            if(cnt == 0){
                maj = nums[i];
                cnt = 1; 
            }
            else if(nums[i] == maj){
                cnt++;
            }
            else cnt--;
        }

        return maj;
        
    }
};