class Solution {
public:
    vector<int>parent,ranki;

    int find(int x){
        if(parent[x]==x)return x;
        else return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int parent_x=parent[x];
        int parent_y=parent[y];

        if(ranki[parent_x]>ranki[parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(ranki[parent_x]<ranki[parent_y]){
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_y]=parent_x;
            ranki[parent_x]++;
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        
        parent.resize(n);
        ranki.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &it:edges){
            int node1=it[0];
            int node2=it[1];

            Union(node1,node2);
        }

        if(find(source)==find(destination))return true;
        else return false;
    }
};