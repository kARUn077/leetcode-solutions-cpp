class Solution {
public:
    int singleNonDuplicate(vector<int>& v){
        int n=v.size();
        //edge case
        if(n==1) return v[0];

        if(v[n-1] != v[n-2]) return v[n-1];
        if(v[0] != v[1]) return v[0];

        int s=1 , e=n-2;
        while(s<=e){
            int m = (e-s)/2 + s;
            if(v[m] != v[m-1] && v[m] != v[m+1]){
                return v[m];
            }

            if((v[m] == v[m-1] && m%2 == 0) || (v[m] == v[m+1] && m%2 == 1)){
                e = m-1;
            }
            else s = m+1;
        }
        return 1;
        
    }
};