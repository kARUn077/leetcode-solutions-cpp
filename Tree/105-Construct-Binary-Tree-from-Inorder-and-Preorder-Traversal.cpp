/*
 * LeetCode Problem 105: Construct Binary Tree from Preorder and Inorder Traversal
 * Link     : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 * Tags     : Tree, Binary Tree, DFS, Recursion, Divide and Conquer
 * Companies: Apple, Microsoft, Bytedance, Google, Citadel, Oracle, Yahoo, Adobe, Square, Uber, Facebook, Twitter, Bloomberg
 * 
 * Time Complexity  : O(N), where N is the number of nodes (each node is visited once)
 * Space Complexity : O(N), for hashmap and recursion stack
 */

 class Solution {
public:
    unordered_map<int, int> inorderIndexMap;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderIndexMap[rootVal];

        root->left = build(preorder, inStart, inIndex - 1);
        root->right = build(preorder, inIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
            inorderIndexMap[inorder[i]] = i;

        return build(preorder, 0, n - 1);
    }
};
