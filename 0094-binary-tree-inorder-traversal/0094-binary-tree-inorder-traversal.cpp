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
    vector<int> Traversal(TreeNode* root,vector<int> &res) {
        if(root==NULL) return res;
        
        Traversal(root->left,res);
        res.push_back(root->val);
        Traversal(root->right,res);
        
        return res;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // return Traversal(root,res);
        if(root == NULL) return res; 
        TreeNode* node = root;
        stack<TreeNode*> st;
        
        while(!st.empty() || node) {
            if(!node) {
                node = st.top();
                st.pop();
                res.push_back(node->val);
                node = node->right;
            }
            else {
                st.push(node);
                node = node->left;
            }
        }
        return res;
        
    }
};