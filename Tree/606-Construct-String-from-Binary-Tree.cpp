/*
 * LeetCode Problem 606: Construct String from Binary Tree
 * Link     : https://leetcode.com/problems/construct-string-from-binary-tree/
 * Tags     : Tree, Depth-First Search, String, Binary Tree
 * Companies: Facebook, Adobe, Amazon, Ibm
 * 
 * Time Complexity : O(N), where N is the number of nodes in the tree
 * Space Complexity: O(H), where H is the height of the tree (due to recursion stack)
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

//approach 1
class Solution {
public:
    //preorder
    string dfs(TreeNode* node){
        if(node==NULL) return "";
        if(node->left==NULL && node->right==NULL) return to_string(node->val);
        else if(node->left && node->right == NULL) return to_string(node->val) + "(" + dfs(node->left) + ")";
        else if(node->left == NULL && node->right) return to_string(node->val) + "(" + ")" + "(" + dfs(node->right) + ")";
        else return to_string(node->val) + "(" + dfs(node->left) + ")" + "(" + dfs(node->right) + ")";
    }

    string tree2str(TreeNode* root){
        return dfs(root);
    }
};

//approach 2
    string dfs(TreeNode* node){
        if(!node) return "";

        string left = dfs(node->left);
        string right = dfs(node->right);

        // If both children are null
        if(left.empty() && right.empty()){
            return to_string(node->val);
        }

        // If only right child (need to include empty ())
        if(left.empty()){
            return to_string(node->val) + "()" + "(" + right + ")";
        }

        // If only left child
        if(right.empty()){
            return to_string(node->val) + "(" + left + ")";
        }

        // If both children exist
        return to_string(node->val) + "(" + left + ")" + "(" + right + ")";
    }

    string tree2str(TreeNode* root){
        return dfs(root);
    }