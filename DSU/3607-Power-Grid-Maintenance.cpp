/*
 * LeetCode Problem 3607: Power Grid Maintenance
 * Link     : https://leetcode.com/problems/power-grid-maintenance
 * Tags     : Disjoint Set, Union Find
 * Companies: [To be updated]
 *
 * Approach : Use Union-Find (DSU) to manage component connectivity. Track which nodes are online.
 * - Each query is either asking for the lowest online node in the component (type 1)
 *   or marking a node offline (type 2).
 * 
 * Time Complexity: O(α(N)) per union/find operation, total ~ O(N + Q log N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    vector<int>parent;
    vector<int>ranki;
    int find(int x){
        if(parent[x]==x)return x;
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

    vector<int> processQueries(int c, vector<vector<int>>& con, vector<vector<int>>& q){
        parent.resize(c+1);
        ranki.resize(c+1,1);
        for(int i=1;i<=c;i++) parent[i]=i;

        for(auto &it:con){
            Union(it[0],it[1]);
        }

        //all online
        vector<bool>online(c+1 ,true);
        
        unordered_map<int ,set<int>>mpp;
        for(int i=1;i<=c;i++){
            mpp[find(i)].insert(i);
        }

        vector<int>ans;
        for(auto &it:q){
            int num=it[1];
            if(it[0]==1){
                //if online
                if(online[num]) ans.push_back(num);
                else{
                    //so check
                    if(mpp[find(num)].empty()) ans.push_back(-1);
                    else ans.push_back(*mpp[find(num)].begin());
                }
            }
            else{
                //make offline
                if(online[num]){
                    online[num]=false;
                    mpp[find(num)].erase(num);
                }
            }
        }
        return ans;
    }
};