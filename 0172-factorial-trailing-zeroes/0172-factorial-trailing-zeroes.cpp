class Solution {
public:
    int trailingZeroes(int n){
        int sum=0;
        int target=5;
        while(target<=n){
            sum+=n/target;
            target*=5;
        }
        return sum;
        
    }
};