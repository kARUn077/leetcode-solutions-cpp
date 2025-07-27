#define ll long long
class Solution {
public:
    long long numOfSubsequences(string s){
        int n=s.size();
        vector<int> pre(n) ,suff(n);  //pre for 'L'  , suff for 'T'
        if(s[0]=='L') pre[0]=1;
        if(s[n-1]=='T') suff[n-1]=1;

        for(int i=1;i<n;i++){
            pre[i]=pre[i-1] + (s[i]=='L' ? 1 : 0);
        }

        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1] + (s[i]=='T' ? 1 : 0);
        }

        //simply add L at starting , or T at ending or C in between where we gain max prod
        ll ans=0, ans_L=0 , ans_T=0;
        ll best_prod=0;

        for(int i=0;i<n;i++){
            ll p = (i-1>=0 ? pre[i-1] : 0);
            ll sf = (i+1<n ? suff[i+1] : 0);

            if(s[i]=='C'){
                //normal
                ans += p*sf;

                //add 'L'
                ans_L += (p+1)*sf;

                //add 'T'
                ans_T += p*(sf+1);
            }
            best_prod = max(best_prod , pre[i]*sf);
        }

        return max({ans + best_prod , ans_L , ans_T});
    }
};