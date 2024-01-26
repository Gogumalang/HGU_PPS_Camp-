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
    TreeNode* rightEnd(TreeNode* node) {
        if(node == NULL) return NULL;
        if(node->right == NULL) return node; 
        return rightEnd(node->right);
    }

    TreeNode* leftEnd(TreeNode* node) {
        if(node == NULL) return NULL;
        if(node->left == NULL) return node; 
        return leftEnd(node->left);
    }

    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* head = leftEnd(root);
        if(root->left != NULL) {
            head = increasingBST(root->left);
            rightEnd(head)->right = root;
            root->left = NULL;
        }
        if(root->right != NULL) {
            TreeNode* right = increasingBST(root->right);
            root->right = right;
        }
        return head; 
    }
};

// 왼쪽 줄기는 가장 오른쪽에 있는 것을 가르키고 
// 오른쪽 줄기는 가장 왼쪽에 있는 것을 가르킨다. 


//  TreeNode* increasingBST(TreeNode* root) {
//         return inorder(root, nullptr);
//     }

//     TreeNode* inorder(TreeNode* node, TreeNode* pre){
//         if(!node) return pre;

//         TreeNode *res = inorder(node->left, node);
//         node->left = nullptr;
//         node->right = inorder(node->right, pre);
//         return res;
//     }