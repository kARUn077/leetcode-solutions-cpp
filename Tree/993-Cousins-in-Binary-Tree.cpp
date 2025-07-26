/*
 * LeetCode Problem 993: Cousins in Binary Tree
 * Link     : https://leetcode.com/problems/cousins-in-binary-tree
 * Tags     : Tree, Depth-First Search, Breadth-First Search, Binary Tree
 * Companies: Amazon, Microsoft, Goldman-sachs, Adobe, Facebook, Bloomberg
 * 
 * Time Complexity  : O(n), where n is the number of nodes in the tree
 * Space Complexity : O(n), for the queue in BFS or recursion stack in DFS
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
    bool isCousins(TreeNode* root, int x, int y){
        if(root==NULL) return false;
        queue<TreeNode* >q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            bool foundx=false ,foundy=false;
            TreeNode* parentx=NULL;
            TreeNode* parenty=NULL;

            while(sz--){
                TreeNode* node=q.front();
                q.pop();

                if(node->left){
                    if(node->left->val ==x){
                        foundx=true;
                        parentx=node;
                    }
                    if(node->left->val ==y){
                        foundy=true;
                        parenty=node;
                    }
                    q.push(node->left);
                }

                if(node->right){
                    if(node->right->val ==x){
                        foundx=true;
                        parentx=node;
                    }
                    if(node->right->val ==y){
                        foundy=true;
                        parenty=node;
                    }
                    q.push(node->right);
                }
            }

            //at this level , check
            if(foundx && foundy){
                return (parentx !=parenty);   //dono same lvl pe mil gye
            }

            if((foundx && !foundy)||(!foundx && foundy)){
                return false;                              //koi ek hi mila
            }
        }
        return false;
    }
};