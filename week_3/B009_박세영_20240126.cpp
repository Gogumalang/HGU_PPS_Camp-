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
    int getHeight(TreeNode* node) {
        if(node== NULL) return 0;
        int right = getHeight(node->right);
        int left = getHeight(node->left); 
        return 1+ max(right,left);
    }
    int max(int right , int left) {
        if(right>left) return right;
        else return left;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int right = getHeight(root->right);
        int left = getHeight(root->left);
        if(abs(right-left) >1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};