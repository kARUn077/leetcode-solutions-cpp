/*
 * LeetCode Problem 113: Path Sum II
 * Link     : https://leetcode.com/problems/path-sum-ii
 * Tags     : Tree, DFS, Backtracking
 * Companies: Baidu, Amazon, Apple, Microsoft, Bytedance, Google, Linkedin, Zillow, Oracle, Adobe, Quora, Facebook, Vmware, Bloomberg
 * 
 * Time Complexity: O(N)  // N = number of nodes (visiting all once)
 * Space Complexity: O(H) // H = height of tree (stack + path vector)
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, int targetSum ,vector<vector<int>>& ans, vector<int>& currPath){
        if(node==NULL)return;

        currPath.push_back(node->val);

        // check if leaf and sum matches
        if(node->left == NULL && node->right == NULL && node->val == targetSum){
            ans.push_back(currPath);
        }

        //left and right child
        dfs(node->left ,targetSum-node->val ,ans ,currPath);
        dfs(node->right ,targetSum-node->val ,ans ,currPath);

        //backtrack
        currPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currPath;
        dfs(root,targetSum ,ans, currPath);
        return ans;
    }
};