class Solution {
public:
#define ll long long
    int longestSubarray(vector<int>& nums) {

        ll n = nums.size();
        ll maxlen = 0;
        ll len = 0;
        ll maxi = *max_element(nums.begin() , nums.end());

        for(ll i=0 ; i< n ; i++){
            if(nums[i] == maxi){
                len++;
                maxlen = max(len , maxlen);
            }

            else len = 0;
        }

        return maxlen;
        
    }
};