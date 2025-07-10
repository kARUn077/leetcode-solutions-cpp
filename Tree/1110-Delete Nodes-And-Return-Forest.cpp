/*
 * LeetCode Problem 1110: Delete Nodes And Return Forest
 * Link     : https://leetcode.com/problems/delete-nodes-and-return-forest
 * Tags     : Tree, DFS, Postorder, Recursion
 * Companies: Amazon, Microsoft, Google, Intuit, Facebook
 * 
 * Time Complexity: O(N)  // N = number of nodes (each visited once)
 * Space Complexity: O(H + M) 
 *   - H = tree height (recursion stack)
 *   - M = number of nodes added to the answer list
 */

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
    //postorder
    vector<TreeNode*>ans;
    TreeNode* dfs(TreeNode* node, unordered_set<int>st , bool isRoot){
        if(node==NULL) return NULL;

        bool deleted = st.count(node->val);

        //first childrens
        node->left = dfs(node->left ,st,deleted);
        node->right = dfs(node->right ,st,deleted);

        //now current node
        if(!deleted && isRoot){
            ans.push_back(node);
        }

        return deleted ? NULL : node;
    }


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& v){
        unordered_set<int>st(v.begin(),v.end());
        bool isRoot=true;
        dfs(root,st,isRoot);
        return ans;
    }
};