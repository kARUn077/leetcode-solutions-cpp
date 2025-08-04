class Solution {
public:
    // brute -> o(n3)
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) return 1;
        int ans = 0;
        // for(int i=0 ; i< n ; i++){
        //     unordered_map<double , int>mpp;  //angle , no.
        //     for(int j=0 ; j< n ; j++){
        //         if(j != i){
        //             int dy = points[j][1] - points[i][1];
        //             int dx = points[j][0] - points[i][0];
        //             double theta = atan2(dy , dx);
        //             mpp[theta]++;
        //         }
        //     }

        //     for(auto it:mpp){
        //         ans = max(ans  , it.second+1);
        //     }
        // }

        for(int i=0 ; i< n ; i++){
            unordered_map<string , int>mpp;  //string(x_y) , no.
            for(int j=0 ; j< n ; j++){
                if(j != i){
                    int dy = points[j][1] - points[i][1];
                    int dx = points[j][0] - points[i][0];
                    
                    int gcd = __gcd(dy ,dx);
                    string key = to_string(dy/gcd) + "_" + to_string(dx/gcd);
                    mpp[key]++;
                }
            }

            for(auto it:mpp){
                ans = max(ans  , it.second+1);
            }
        }


        return ans;    
    }
};