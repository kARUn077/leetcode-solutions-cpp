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
    void dfs(TreeNode* node ,int level , int x , auto& mp){
        if(node==NULL) return ;
        mp[x][level].push_back(node->val);
        dfs(node->left,level+1,x-1,mp);
        dfs(node->right,level+1,x+1,mp);

    }


    vector<vector<int>> verticalTraversal(TreeNode* root){
        vector<vector<int>> ans;
        map<int,map<int, vector<int>>> mpp;//x->map

        dfs(root,0,0 ,mpp); //level,x

        for(auto&[x,_]:mpp){
            vector<int>temp;
            for(auto&[y,z]:mpp[x]){
                vector<int>v;
                v=z; sort(v.begin(),v.end());
                for(auto&t:v)temp.push_back(t);
            }
            ans.push_back(temp);
        }
        return ans;



        // return ans;
    }
};