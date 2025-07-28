class Solution {
public:
    bool checkValidString(string s){
        int minOpen = 0; // minimum possible open brackets
        int maxOpen = 0; // maximum possible open brackets
        
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen = max(minOpen - 1, 0);
                maxOpen--;
            } else { // c == '*'
                minOpen = max(minOpen - 1, 0); // treat '*' as ')'
                maxOpen++;                    // or as '('
            }
            
            if (maxOpen < 0) return false; // too many ')'
        }
        
        return minOpen == 0;


    //     int n=s.size();
    //     int cnt1=0 , cnt2=0 ,cnt3=0; 
    //     for(int i=0;i<n;i++){
    //         if(s[i]=='(')cnt1++;
    //         else if(s[i]==')')cnt2++;
    //         else cnt3++;
    //     }
    //     if(abs(cnt1-cnt2) > cnt3)return false;

    //     if(cnt1==cnt2){
    //         string s2;
    //         for(int i=0;i<n;i++){
    //             if(s[i] !='*'){
    //                 s2+=s[i];
    //             }
    //         }
           
    //         stack<char>st;
            
    //         for(int i=0;i<s2.size();i++){
    //             if(!st.empty() && s2[i]==')' && st.top()=='('){
    //                 st.pop();
    //             }
    //             else st.push(s2[i]);
    //         }
    //         return st.empty();
    //     }
    //     else{
    //         if(cnt1 < cnt2){
    //             for(int i=0;i<n;i++){
    //                 if(s[i]=='*')s[i]='(';
    //             }
                
    //         }
           
    //         else{
    //             for(int i=0;i<n;i++){
    //                 if(s[i]=='*')s[i]=')';
    //             }
    //         }
            
    //         stack<char>st;
    //         for(int i=0;i<n;i++){
    //             if(!st.empty() && s[i]==')' && st.top()=='('){
    //                 st.pop();
    //             }
    //             else st.push(s[i]);
    //         }
    //         return st.empty();
    //     }
    //     return true;


    // //   when input=  "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"

    }
};