class Solution {
public:
    vector<string> getTokens(string s){
        stringstream ss(s);
        string token="";
        vector<string> tokens;

        while(getline(ss ,token , ' ')){
            if(!token.empty()) tokens.push_back(token);
        }

        return tokens;
    }


    string reverseWords(string s){
        //trim initial gaps  -> is is avoided ,since we use (!token.empty())
        // int i=0;
        // while(s[i]==' '){
        //     i++;
        // }
        // s=s.substr(i);
        vector<string>v = getTokens(s);
        reverse(v.begin() ,v.end());

        string ans="";
        for(int i=0;i<v.size() ; i++){
            if(i!= v.size()-1){
                ans += v[i];
                ans += " ";
            }
            else{
                ans += v[i];
            }
        }
        return ans;
    }
};
