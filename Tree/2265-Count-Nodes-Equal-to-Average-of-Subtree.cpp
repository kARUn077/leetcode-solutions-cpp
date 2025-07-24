/*
 * LeetCode Problem 2265: Count Nodes Equal to Average of Subtree
 * Link     : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree
 * Tags     : Tree, Depth-First Search, Binary Tree
 * Companies: Amazon, Google, Facebook
 * 
 * Time Complexity  : O(N), where N is the number of nodes in the tree
 * Space Complexity : O(H), where H is the height of the tree (for recursion stack)
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
    pair<int,int> dfs(TreeNode* node ,int& cnt){
        if(node==NULL) return {0,0};

        auto l=dfs(node->left,cnt);
        auto r=dfs(node->right,cnt);

        int sum=node->val + l.first + r.first;
        int counts = 1 + l.second + r.second;

        int avg = (float)sum/counts;
        if(avg==node->val) cnt++;

        return {sum,counts};
    }

    int averageOfSubtree(TreeNode* root){
        int cnt=0;
        dfs(root,cnt);
        return cnt;
    }
};