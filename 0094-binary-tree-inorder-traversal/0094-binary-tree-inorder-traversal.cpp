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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;

        TreeNode* curr = root;

        while(curr){
            if(curr -> left == NULL){
                inorder.push_back(curr -> val);
                curr = curr -> right;
            }
            else{
                //jab curr ka left null nahi h , toh ab predecessor ka use karenge
                TreeNode* pred = curr-> left;
                while(pred -> right != NULL && pred -> right != curr){
                    pred = pred -> right;   //pred ko right mein bhejte rahenge
                }

                if(pred -> right == NULL){
                    pred -> right = curr;   //branch banna rahe h
                    curr = curr -> left;
                }
                else{
                    //pred -> right != NULL , matlab branch pehle se ban chuki h , toh break it
                    pred -> right = NULL;
                    inorder.push_back(curr -> val);
                    curr = curr -> right;
                }
            }  
        }
        return inorder;
    }
};