/*
 * LeetCode Problem 1339: Maximum Product of Splitted Binary Tree
 * Link     : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree
 * Tags     : Tree, DFS, Recursion
 * Companies: Amazon,Bytedance, Two Sigma, Microsoft
 * 
 * Time Complexity : O(N)  // Traverse every node twice (to calculate sums and max product)
 * Space Complexity: O(H)  // H = height of tree (due to recursion stack)
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

#define ll long long 
#define mod 1000000007
class Solution {
public:
    ll maxProd=1;
    ll ans=0;

    ll dfs1(TreeNode* node){
        if(node==NULL) return 0;
        return dfs1(node->left) + dfs1(node->right) + node->val;
    }


    ll dfs2(TreeNode* node, int totalSum){
        if(node==NULL) return 0;

        ll left=dfs2(node->left ,totalSum);
        ll right=dfs2(node->right ,totalSum);

        ll currSum = node->val + left + right;
        cout<<currSum<<" ";
        maxProd = max(maxProd , (totalSum-currSum)*currSum);
        return currSum;
    }


    int maxProduct(TreeNode* root){
        vector<int>sum;
        dfs1(root);         //to get totalSum
        ll totalSum=dfs1(root);

        dfs2(root,totalSum);
        return maxProd%mod;
    }
};
