class Solution {
public:
    vector<string> getTokens(string s){
        stringstream ss(s);
        string token="";
        vector<string>tokens;

        while(getline(ss , token , ' ')){
            if(!token.empty()) tokens.push_back(token);
        }

        return tokens;
    }


    string generateTag(string s){
        
        //adjust case ,when in initially have gap
        // int i=0;
        // while(!s.empty() && s[i]==' '){
        //     i++;
        // }
        // s = s.substr(i, s.size()-i);

        vector<string> v = getTokens(s);
        string ans="#";
     
        int n=v.size();
        if(n==0) return "#";

        for(int i=0;i<v[0].size();i++){
            ans += tolower(v[0][i]);
            if(ans.size() == 100) break;
          
        }
      
        if(ans.size()==100) return ans;

        for(int i=1;i<n;i++){
            for(int j=0;j<v[i].size();j++){
                
                if(ans.size()==100)break;
                if(j==0){
                    ans += toupper(v[i][j]);
                }
                else ans += tolower(v[i][j]);
                if(ans.size()==100)break;
            }
        }

        return ans;
    }
};