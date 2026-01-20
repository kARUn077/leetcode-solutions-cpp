class Solution {
public:
    bool check(string temp){
        int n=temp.size();
        vector<int> small(26,0) , large(26,0);

        for(int i=0;i<n;i++){
            if(temp[i] >= 'a' && temp[i] <= 'z'){
                small[temp[i]-'a']++;
            }
            if(temp[i] >= 'A' && temp[i] <= 'Z'){
                large[temp[i]-'A']++;
            }
        }

        for(int i=0;i<26;i++){
            if(small[i] > 0 && large[i] == 0) return false;
            if(small[i] == 0 && large[i] > 0) return false;
        }

        return true;
    }
    

    string longestNiceSubstring(string s){
        int n=s.size();
        int maxi=0;
        string ans="";
        //brute force
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp += s[j]; 

                //check each substring
                if(check(temp)== true){
                    if(temp.size() > maxi){
                        ans = temp;
                        maxi = temp.size();
                    }
                }
            }
        }

        return ans;
    }
};