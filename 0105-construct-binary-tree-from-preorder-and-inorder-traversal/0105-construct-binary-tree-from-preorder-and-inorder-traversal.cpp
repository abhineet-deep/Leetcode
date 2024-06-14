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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;

        for(int i = 0;i<inorder.size();i++) inMap[inorder[i]] = i;
        TreeNode* root = buildUniqueTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);

        return root;
    }
    TreeNode* buildUniqueTree(vector<int>& preorder, int preStart, int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>& inMap) {
        if(preStart > preEnd || inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIndex = inMap[root->val];
        int numsLeft = inIndex - inStart;

        root->left = buildUniqueTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inIndex-1,inMap);
        root->right = buildUniqueTree(preorder,preStart+1+numsLeft,preEnd,inorder,inIndex+1,inEnd,inMap);

        return root;
    }
};