class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size(),m=nums2.size();
        vector<int>nge(m);
        stack<int>st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty())nge[i]=-1;
            else nge[i]=st.top();  //pehle nge set karo
            st.push(nums2[i]);     //fir st mein push karo
        }

        //for nums1
        unordered_map<int,int>mpp; //val,ind
        for(int i=0;i<m;i++){
            mpp[nums2[i]]=i;
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            int itsindex=mpp[nums1[i]];
            ans.push_back(nge[itsindex]);
        }

        return ans;
    }
};