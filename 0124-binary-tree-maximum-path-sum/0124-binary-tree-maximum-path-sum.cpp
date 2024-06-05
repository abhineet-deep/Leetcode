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

    int findSum(TreeNode* root,int& maxi) {
        if(!root) return 0;

        int ls = findSum(root->left,maxi);
        int rs = findSum(root->right,maxi);

        maxi = max(maxi,max(root->val,max(root->val+ls+rs,max(root->val+ls, root->val+rs))));

        return max(root->val,max(root->val+ls, root->val+rs));
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findSum(root,maxi);
        return maxi;
    }
};