/*
 * LeetCode Problem 1361: Validate Binary Tree Nodes
 * Link     : https://leetcode.com/problems/validate-binary-tree-nodes
 * Tags     : Graph, Tree, Breadth-First Search, Depth-First Search, Union Find
 * Companies: Future First, Coditas Technology, Nevi Encre, Amazon, Techwave Consulting, Netcore, Mettle, Intuit, Mathway, Olx, Mindstix, Josh Technologies, Makemytrip, Facebook, Vmware, Ion
 * 
 * Time Complexity  : O(N), where N is the number of nodes (to build the graph and perform BFS)
 * Space Complexity : O(N), for adjacency list, visited array, and queue
 */

 class Solution {
public:
    void dfs(int i ,vector<vector<int>> &adj , int& cnt ,vector<bool>& vis){
        vis[i]=true;
        cnt++;
        cout<<i<<" ";
        cout<<endl;
        for(auto &it:adj[i]){
            if(!vis[it]){
                dfs(it,adj ,cnt,vis);
                cout<<i<<" ";
            } 
        }
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild){
        vector<vector<int>> adj(n);
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            int node=i;
            int lchild=leftChild[i];
            int rchild=rightChild[i];

            if(lchild!=-1){
                if(mpp.find(lchild) !=mpp.end()) return false;

                mpp[lchild]=node;
                adj[node].push_back(lchild);
            }

            if(rchild!=-1){
                if(mpp.find(rchild) !=mpp.end()) return false;

                mpp[rchild]=node;
                adj[node].push_back(rchild);
            }
        }


        //find root
        int root=-1;
        int rootcnt=0;
        for(int i=0;i<n;i++){
            if(mpp.find(i)==mpp.end()){ rootcnt++; root=i;}
        }

        if(rootcnt>1 || rootcnt==0) return false;
        //agar rootcnt=1 ,but still needs to check ,whether it is in connectd component

        int cnt=0;
        vector<bool>vis(n,false);
        queue<int> q;
        q.push(root);
        vis[root]=true;
        cnt++;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto &it:adj[node]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                    cnt++;
                }
            }
        }
        
        // dfs(root,adj,cnt,vis);
        
        return (cnt==n);
    }
};
