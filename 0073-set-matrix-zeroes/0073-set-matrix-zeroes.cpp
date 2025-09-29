class Solution {
public:
    void setZeroes(vector<vector<int>>& v){
        int n=v.size();
        int m=v[0].size();

        //m2 sc = o(1)
        //in place  
        bool firstrowinfected = false;
        bool firstcolinfected = false;

        for(int i=0;i<n;i++){
            if(v[i][0]==0){
                firstcolinfected = true;
            }
        }

        for(int j=0;j<m;j++){
            if(v[0][j]==0){
                firstrowinfected = true;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(v[i][j] == 0){
                    v[i][0] = 0; 
                    v[0][j] = 0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(v[i][0] == 0 || v[0][j] == 0){
                    v[i][j] = 0;
                }
            }
        }

        if(firstrowinfected){
            for(int j=0;j<m;j++){
                v[0][j] = 0;
            }
        }

        if(firstcolinfected){
            for(int i=0;i<n;i++){
                v[i][0] = 0;
            }
        }
    }
};