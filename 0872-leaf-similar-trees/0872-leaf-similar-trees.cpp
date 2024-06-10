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

    vector<int>myVector(TreeNode* root, vector<int>&v){
        
        if(!root) return v;
        if(!root->left  && !root->right) v.push_back(root->val);
        myVector(root->left,v);
        myVector(root->right,v);
        return v;
  }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        return  myVector(root1, v1) == myVector(root2,v2);
    }
};