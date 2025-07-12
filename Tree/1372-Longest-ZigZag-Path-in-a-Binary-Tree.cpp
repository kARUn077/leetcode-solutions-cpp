/*
 * LeetCode Problem 3593: Make a Tree of Even Sum
 * Link     : https://leetcode.com/problems/make-a-tree-of-even-sum
 * Tags     : Tree, DFS, Greedy, Graph
 * Companies: [To be updated]
 * 
 * Time Complexity  : O(N), where N is the number of nodes (each visited once)
 * Space Complexity : O(N), for adjacency list and recursion stack
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
    int ans=0;
    void dfs(TreeNode* node, bool goleft ,int len){
        if(node==NULL) return ;

        ans=max(ans,len);

        if(goleft){
            dfs(node->left ,false, len+1);
            dfs(node->right ,true , 1);
        }
        else{
            dfs(node->left , false ,1);
            dfs(node->right ,true , len+1);
        }
    }

    int longestZigZag(TreeNode* root){
        dfs(root,true,0);
        dfs(root,false,0);
        return ans;
    }
};