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
public:;
    int findTilt(TreeNode* root) {
        if(root == NULL) return 0;  
        int t_sum = abs(sum(root->left) - sum(root->right));
        return t_sum + findTilt(root->left) + findTilt(root->right);
        
    }
    int sum(TreeNode* node) {
        if(node ==NULL) return 0;
        return node->val + sum(node->left) + sum(node->right);
    }
};