/*
 * LeetCode Problem 106: Construct Binary Tree from Inorder and Postorder Traversal
 * Link     : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 * Tags     : Tree, Binary Tree, DFS, Recursion, Divide and Conquer
 * Companies: Mathworks, Amazon, Microsoft, Shopee, Facebook, Twitter, Bloomberg
 * 
 * Time Complexity  : O(N), where N is the number of nodes (each node is visited once)
 * Space Complexity : O(N), for hashmap and recursion stack
 */

 class Solution {
public:
    unordered_map<int, int> inorderIndexMap;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderIndexMap[rootVal];

        // NOTE: build right subtree first because postorder goes Left -> Right -> Root
        root->right = build(postorder, inIndex + 1, inEnd);
        root->left = build(postorder, inStart, inIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIndex = n - 1;

        for (int i = 0; i < n; ++i)
            inorderIndexMap[inorder[i]] = i;

        return build(postorder, 0, n - 1);
    }
};
