class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& v){
        int n=v.size();
        vector<int> ans(n);
        vector<int> last(32,-1);
        for(int i=n-1;i>=0;i--){
            for(int k=0;k<=31;k++){
                if(v[i] & (1<<k)){
                    last[k]=i;
                }
            }

            int maxInd=i;
            for(int k=0;k<=31;k++){
                if(last[k] !=-1){
                    maxInd=max(maxInd , last[k]);
                }
            }

            ans[i]=maxInd-i+1;
        }
        return ans;


        // misunderstanding
        // unordered_map<int,vector<int>> mpp;
        // for(int i=0;i<n;i++){
        //     for(int k=0;k<=31;k++){
        //         if(v[i] & (1<<k)){
        //             mpp[k].push_back(i);
        //         }
        //     }
        // }
        // //no of set bits in maximum or is mpp.size();
        // for(auto &it:mpp){
        //     vector<int> vec=it.second;
        //     cout<<it.first<<" " <<"-> " ;
        //     for(auto p:vec){
        //         cout<<p<<" ";
        //     }
        //     cout<<endl;

        // }

        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     int len=1;
        //     for(auto &it:mpp){
        //         vector<int> vec=it.second;
        //         auto it_lb = lower_bound(vec.begin(), vec.end(), i);
        //         if(it_lb != vec.end()){
        //             int idx = *it_lb;
        //             len = max(len, idx - i + 1);
        //         }
        //     }
        //     ans.push_back(len);
        // }

        // return ans;
    }
};