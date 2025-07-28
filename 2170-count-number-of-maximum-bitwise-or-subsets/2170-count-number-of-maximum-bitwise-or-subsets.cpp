class Solution {
public:
    int solve(int index, int current_or, int max_or, vector<int>& nums) {
       
        if (index == nums.size()) {
            return (current_or == max_or) ? 1 : 0;
        }

        
        int exclude = solve(index + 1, current_or, max_or, nums);

        
        int include = solve(index + 1, current_or | nums[index], max_or, nums);

        
        return exclude + include;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        
        int max_or = 0;
        for (int num : nums) {
            max_or |= num;  
        }

 
        return solve(0, 0, max_or, nums);
    }
};
