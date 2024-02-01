/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void post(Node* node, vector<int>& v) {
        if(node == NULL) return ;
        for(int i =0;i<node->children.size();i++) {
            post(node->children[i],v);
        }
        v.push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        post(root,ans);
        return ans;
    }
};