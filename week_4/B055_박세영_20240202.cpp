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
    vector<int> leafSequence(TreeNode* node){
        vector<int> ans;
        if(!(node->right)&&!(node->left)) {
            ans.push_back(node->val);
            return ans;
        }
        if(node->right) {
            for(auto x : leafSequence(node->right)){
                ans.push_back(x);
            }
        }
        if(node->left) {
            for(auto x : leafSequence(node->left)){
                ans.push_back(x);
            }
        }
        return ans;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1 = leafSequence(root1);
        vector<int> r2 = leafSequence(root2);
        if(r1.size() != r2.size() ) return false;
        for(int i=0;i<r1.size();i++) {
            if(r1[i]!=r2[i]) return false;
        }
        
        return true;
    }
};