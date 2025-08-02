class Solution {
public:
    vector<string> getTokens(string s){
        stringstream ss(s);
        string token = "";
        vector<string> tokens;

        while(getline(ss, token, '+')){
            if(!token.empty()) tokens.push_back(token);
        }

        return tokens;
    }

    string complexNumberMultiply(string num1, string num2) {
        num1 = num1.substr(0 , num1.size()-1);
        num2 = num2.substr(0 , num2.size()-1);

        vector<string>v1 = getTokens(num1);
        vector<string>v2 = getTokens(num2);

        int real=stoi(v1[0]) * stoi(v2[0]);
        real -= stoi(v1[1]) * stoi(v2[1]);
        
        int img=stoi(v1[0]) * stoi(v2[1]);
        img += stoi(v1[1]) * stoi(v2[0]);

        string ans;
        ans += to_string(real) + '+' + to_string(img) + 'i';
        return ans;
    }
};