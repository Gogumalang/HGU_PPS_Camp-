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
    vector<string> allPath(TreeNode* node) {
        vector<string> ans;
        if(!(node->right)&&!(node->left)) {
            ans.push_back(to_string(node->val));
            return ans;
        }
        if(node->right) {
            for(auto s: allPath(node->right)) {
                ans.push_back(to_string(node->val)+s);
            }
        }
        if(node->left) {
            for(auto s: allPath(node->left)) {
                ans.push_back(to_string(node->val)+s);
            }
        }
        return ans;
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> path = allPath(root);
        int sum =0;
        for(auto s : path) {
            int b = 0;
            int n = 0;
            for(int i = s.size()-1;i>=0;i--) {
                if(s[i] == '1') b += pow(2,n);
                n++;
            }
            sum += b;
        }
        return sum;
    }
};