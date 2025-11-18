class Solution {
public:
    string reverseParentheses(string s) {

       // ***** ---> Wormhole Teleportation technique  O(n^2)

       string ans = "";

       int n = s.size();

       vector<int> indexes(n , 0);

       stack<int> st;

       for(int i=0 ; i<n ; i++){
            if(s[i] == '('){
                st.push(i);    
            }

            else if(s[i] == ')'){
                indexes[st.top()] = i;
                indexes[i] = st.top();
                st.pop();
            }
       }

       int dir = 1;
       for(int i=0 ; i< n ; i+= dir){
            if(s[i] == '(' || s[i] == ')'){
                i = indexes[i];
                dir = (-1)*dir;
            }
            else {
                ans += s[i];
            }
       }

       return ans;

        
    }
};