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
    vector<int> getLength(TreeNode* node) {
        vector<int> ans;
        if(node==NULL) {
            for(int i=0;i<2;i++) {
                ans.push_back(0);
            }
            return ans;
        }
        vector<int> right = getLength(node->right);
        int right_Len = right[0];
        int right_loopLen = right[1];

        vector<int> left = getLength(node->left);
        int left_Len = left[0];
        int left_loopLen = left[1];

        int loopLen = right_Len + left_Len;

        ans.push_back(max(right_Len,left_Len)+1);

        if(loopLen <right_loopLen){
            if(right_loopLen <left_loopLen) ans.push_back(left_loopLen);
            else ans.push_back(right_loopLen);
        }
        else {
            if(loopLen <left_loopLen) ans.push_back(left_loopLen);
            else ans.push_back(loopLen);
        }

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        vector<int> right = getLength(root->right);
        int right_Len = right[0];
        int right_loopLen = right[1];

        vector<int> left = getLength(root->left);
        int left_Len = left[0];
        int left_loopLen = left[1];

        int loopLen = right_Len + left_Len;

        if(loopLen <right_loopLen){
            if(right_loopLen <left_loopLen) return left_loopLen;
            else return right_loopLen;
        }
        else {
            if(loopLen <left_loopLen) return left_loopLen;
            else return loopLen;
        }

        
    }
};

// 오른쪽,왼쪽 리턴받은것이 총 각각 세개이다. 
// 자신의 오른쪽 단일 길이, 왼쪽 단일 길이, 노드를 포함한 길이 
// 총 4가지가 나온다. 오 + 오 , 왼 오, 오 왼, 왼왼, 왼쪽 노드, 오른쪽 노드 
// 여기서 가장 긴 것이 노드를 합친 길이가 된다. 
// 그리고 가장 긴 단일 길이도 나오게 된다. 
// 오른쪽 노드에서 둘중 단일 길이를 비교하여 긴것이 오른 단일 길이가 된다. 
// 왼쪽 노드에서도 비교하여 정하게 된다. 


    // int solve(TreeNode* root, int &ans){
    //     if(root==NULL)   return 0;

    //     int left = solve(root->left, ans);
    //     int right = solve(root->right, ans);
    //     ans = max(ans, left + right);

    //     return max(left, right) + 1;
    // }

    // int diameterOfBinaryTree(TreeNode* root) {
    //     int ans = 0;
    //     solve(root, ans);
    //     return ans;
    // }