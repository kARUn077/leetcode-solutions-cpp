class Solution {
public:
    void IfGreaterSwap(vector<int> &arr1, vector<int> &arr2, int ind1,int ind2)
    {
        if(arr1[ind1]>arr2[ind2])
        swap(arr1[ind1],arr2[ind2]);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=m+n;
        int gap=(len/2)+len%2;
        while(gap>0)
        {
            int left=0,right=left+gap;
            while(right<len)
            {
                if(left<m && right>=m)
                {
                    IfGreaterSwap(nums1,nums2,left,right-m);
                }
                else if(left>=m)
                {
                    IfGreaterSwap(nums2,nums2,left-m,right-m);
                }
                else
                {
                    IfGreaterSwap(nums1,nums1,left,right);
                }
                left++;
                right++;
            }
            if(gap==1)
            break;
            gap=(gap/2)+gap%2;
        }
        int right=0;
        for(int i=m;i<len;i++)
        {
            nums1[i]=nums2[right];
            right++;
        }
        return;
    }
};