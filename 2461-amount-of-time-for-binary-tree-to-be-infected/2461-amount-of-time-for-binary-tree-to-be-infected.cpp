/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void dfs(TreeNode* node ,TreeNode* par){
        if(node==NULL) return ;

        if(node->left){
            parent[node->left]=node;
            dfs(node->left ,node);
        }

        if(node->right){
            parent[node->right]=node;
            dfs(node->right ,node);
        }
    }

    TreeNode* findStart(TreeNode* node , int start){
        if(!node) return NULL;
        if(node->val==start) return node;

        TreeNode* left= findStart(node->left , start);
        if(left) return left;
        TreeNode* right= findStart(node->right , start);
        return right;
    }


    int amountOfTime(TreeNode* root, int start){
        dfs(root,NULL);  //to keep record of parent
        int maxi=0;
        TreeNode* startNode=findStart(root ,start);
        unordered_set<TreeNode* >vis;
        queue<pair<TreeNode* ,int>> q;
        q.push({startNode,0});
        vis.insert(startNode);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode* node=q.front().first;
                int time=q.front().second;
                q.pop();

                if(node->left && !vis.count(node->left)){
                    q.push({node->left , time+1});
                    vis.insert(node->left);
                    maxi=max(maxi ,time+1);
                }

                if(node->right && !vis.count(node->right)){
                    q.push({node->right , time+1});
                    vis.insert(node->right);
                    maxi=max(maxi ,time+1);
                }

                if(parent.count(node) && !vis.count(parent[node])){
                    q.push({parent[node] , time+1});
                    vis.insert(parent[node]);
                    maxi=max(maxi ,time+1);
                }
            }    
        }
        return maxi;
    }
};