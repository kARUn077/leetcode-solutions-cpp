/*
 * LeetCode Problem 652: Find Duplicate Subtrees
 * Link     : https://leetcode.com/problems/find-duplicate-subtrees
 * Tags     : Tree, Depth-First Search, Hash Map, Binary Tree, String Hashing
 * Companies: Amazon, Microsoft, Google, Lyft, Oracle, Uber, Facebook, Bloomberg
 * 
 * Time Complexity  : O(N * H), where N is number of nodes and H is height of the tree (string length)
 * Space Complexity : O(N * H) for hashmap and recursion stack
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
    unordered_map<string,int> mpp;
    vector<TreeNode* >ans;

    string dfs(TreeNode* node){
        if(node==NULL) return "N";

        string left=dfs(node->left);
        string right=dfs(node->right);

        string s=to_string(node->val) + "," + left + "," + right;

        mpp[s]++;
        if(mpp[s]==2){
            ans.push_back(node);
        }

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){
        if(root==NULL) return ans;
        dfs(root);
        return ans;
    }
};