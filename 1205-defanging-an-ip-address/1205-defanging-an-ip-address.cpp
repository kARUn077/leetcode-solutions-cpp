class Solution {
public:
    vector<string> getTokens(string s){
        stringstream ss(s);
        string token = "";
        vector<string> tokens;

        while (getline(ss, token, '.')) {
            if (!token.empty()) tokens.push_back(token);
        }

        return tokens;
    }

    string defangIPaddr(string s){
        vector<string> v = getTokens(s);
        string ans="";

        for(int i=0;i<v.size();i++){
            ans += v[i];
            if(i != v.size()-1) ans += "[.]";
        }
        return ans;
    }
};