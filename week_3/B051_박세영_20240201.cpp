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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root->left&&!root->right) {
            ans.push_back(to_string(root->val));
            return ans;
        }
        if(root->left){
            for(auto s : binaryTreePaths(root->left)) {
                string val = to_string(root->val) + "->";
                ans.push_back(val+s);
            }
        }
        if(root->right){
            for(auto s : binaryTreePaths(root->right)) {
                string val = to_string(root->val) + "->";
                ans.push_back(val+s);
            }
        }
        return ans;
    }
};