class Solution {
public:
    vector<int> majorityElement(vector<int>& v){
        // Boyer-Moore
        int n=v.size();
        int cnt1=0 ,cnt2=0;
        int maj1=INT_MAX ,maj2=INT_MAX;

        for(int i=0;i<n;i++){
            if(v[i]==maj1){
                cnt1++;
            }
            else if(v[i]==maj2){
                cnt2++;
            }
            else if(cnt1==0){
                maj1=v[i];
                cnt1=1;
            }
            else if(cnt2==0){
                maj2=v[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        //now check
        cnt1=0;
        cnt2=0;

        for(auto it:v){
            if(it==maj1) cnt1++;
            if(it==maj2) cnt2++;
        }

        vector<int>ans;
        if(cnt1>(n/3)) ans.push_back(maj1);
        if(cnt2>(n/3)) ans.push_back(maj2);

        return ans;
    }
};