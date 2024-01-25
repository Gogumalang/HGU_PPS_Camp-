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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        int left_sum =0;
        if((root->left!=NULL)&& (root->left->left == NULL && root->left->right ==NULL)) left_sum += root->left->val;

        return left_sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

