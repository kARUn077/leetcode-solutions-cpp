class Solution {
public:
    //no dp
    int jump(vector<int>& nums){
        int n=nums.size();

        int l=0,r=0;
        int maxIndex=0;
        int jumps=0;
        while(r<n-1){
            maxIndex=0;
            for(int i=l;i<=r;i++){
                maxIndex=max(maxIndex , i + nums[i]);
            }
            jumps++;

            l=r+1;
            r=maxIndex;

            cout<<jumps<<" "<<l<<" "<<r<<endl;
        }

        return jumps;
    }
};