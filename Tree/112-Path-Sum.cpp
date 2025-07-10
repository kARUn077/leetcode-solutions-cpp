/*
 * LeetCode Problem 112: Path Sum
 * Link     : https://leetcode.com/problems/path-sum
 * Tags     : Tree, DFS, Recursion
 * Companies: Amazon, Apple, Microsoft, Zillow, Oracle, Bloomberg, Adobe ,Facebook ,Walmart Global Tech
 * 
 * Time Complexity: O(N)  // where N is the number of nodes
 * Space Complexity: O(H) // call stack height (H = tree height)
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
    //top-down dfs
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;

        //check if leaf, current node
        if(root->left==NULL && root->right==NULL){
            return (root->val==targetSum);
        }

        return hasPathSum(root->left ,targetSum-root->val) || hasPathSum(root->right ,targetSum-root->val);
    }
};