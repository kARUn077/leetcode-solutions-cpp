class Solution {
public:
    vector<int>parent,ranki;
    
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(ranki[x_parent]>ranki[y_parent]){
            parent[y_parent]=x_parent;
        }else if(ranki[x_parent]<ranki[y_parent]){
            parent[x_parent]=y_parent;
        }else{
            parent[x_parent]=y_parent;
            ranki[y_parent]++;
        }
    }

    int removeStones(vector<vector<int>>& stones){
        //no. of connected components jaisa
        int n=stones.size();
        parent.resize(n);
        ranki.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int group=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[j][0]==stones[i][0] || stones[j][1]==stones[i][1]){
                    Union(i,j);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(parent[i]==i) group++;
        }

        return n-group;
    }
};