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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *t = new TreeNode(nums[(int)nums.size()/2]);
        TreeNode *p = t;
        for(int i=0;i<nums.size();i++) {
            TreeNode *tmp = new TreeNode(nums[i]);
            while(1) {
                if(tmp->val==p->val) {
                    break;
                }
                else if(tmp->val<p->val) {
                    if(p->left == NULL) {
                        p->left = tmp;
                        break;
                    }
                    else p= p->left;
                }
                else {
                    if(p->right == NULL) {
                        p->right = tmp;
                        break;
                    }
                    else p= p->right;
                }
            }
            p = t;
        }
        return t;
    }
};