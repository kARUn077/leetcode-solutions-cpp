class Solution {
public:
    bool hasDuplicate(string s1, string s2){
        unordered_map<char,int>mpp;
        for(auto &ch:s1){
            mpp[ch]++;
        }
        for(auto &ch:s2){
            mpp[ch]++;
        }

        for(auto &it:mpp){
            if(it.second>1) return true;
        }
        return false;
    }

    int solve(int i,int n,string temp ,vector<string>& arr){
        //base case
        if(i>=n) return temp.size();

        int include=0;
        int exclude=0;

        if(hasDuplicate(arr[i] ,temp)){
            exclude = solve(i+1 , n, temp ,arr);
        }
        else{
            include = solve(i+1 ,n ,temp+arr[i] ,arr);
            exclude = solve(i+1 ,n , temp ,arr);
        }

        return max(exclude , include);
    }

    int maxLength(vector<string>& arr){
        int n=arr.size();
        return solve(0,n,"",arr);
    }
};