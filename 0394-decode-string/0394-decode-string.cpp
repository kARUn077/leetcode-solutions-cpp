class Solution {
public:
    string decodeString(string s){
        stack<int> numbers;
        stack<string> strings;

        string curr="";
        int num=0;

        for(char ch:s){
            if(isdigit(ch)) num = num*10 + (ch-'0');
            else if(ch=='['){
                //abhi tak ki string aur number ko stack mein daaldo , aur unko reset kardo
                numbers.push(num);
                strings.push(curr);
                num=0;
                curr="";
            }
            else if(ch==']'){
                int k = numbers.top();
                numbers.pop();

                string temp = strings.top();
                strings.pop();

                while(k--) temp += curr;
                curr = temp;
            }
            else curr += ch;
        }

        return curr;
    }
};