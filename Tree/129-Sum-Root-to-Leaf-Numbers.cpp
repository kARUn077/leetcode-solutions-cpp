/*
 * LeetCode Problem 129: Sum Root to Leaf Numbers
 * Link     : https://leetcode.com/problems/sum-root-to-leaf-numbers
 * Tags     : Tree, Depth-First Search, Binary Tree
 * Companies: Microsoft, Amazon, Bloomberg, Facebook,, Google, Servicenow, Ebay, Bloomberg
 * 
 * Time Complexity  : O(N), where N is the number of nodes in the tree
 * Space Complexity : O(H), where H is the height of the tree (due to recursion)
 */

 //Approach 1

 class Solution {
public:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;

        // Update the number formed so far
        current = current * 10 + node->val;

        // If it's a leaf, return the complete number
        if (!node->left && !node->right)
            return current;

        // Combine left and right subtree sums
        int leftSum = dfs(node->left, current);
        int rightSum = dfs(node->right, current);

        return leftSum + rightSum;
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

//Approach2 
vector<string> dfs(TreeNode* node){
        if(node==NULL) return {};
        if(node->left==NULL && node->right==NULL){
            return {to_string(node->val)};
        }

        vector<string>path;
        vector<string>left= dfs(node->left);
        vector<string>right= dfs(node->right);

        for(int i=0;i<left.size();i++){
            path.push_back(left[i] + to_string(node->val));
        }

        for(int i=0;i<right.size();i++){
            path.push_back(right[i] + to_string(node->val));
        }

        return path;
    }

    int sumNumbers(TreeNode* root){
        vector<string>path=dfs(root);
        
        for(int i=0;i<path.size();i++){
            reverse(path[i].begin(),path[i].end());
        }

        int sum=0;
        for(int i=0;i<path.size();i++){
            sum +=stoi(path[i]);
        }
        return sum;       
    }

